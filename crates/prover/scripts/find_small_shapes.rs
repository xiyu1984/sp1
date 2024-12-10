use std::{collections::BTreeMap, path::PathBuf};

use clap::Parser;
use p3_util::log2_ceil_usize;
use sp1_core_executor::RiscvAirId;
use sp1_core_machine::utils::setup_logger;
use sp1_stark::shape::Shape;

#[derive(Parser, Debug)]
#[clap(author, version, about, long_about = None)]
struct Args {
    #[clap(short, long)]
    maximal_shapes_json: PathBuf,
    #[clap(short, long, value_delimiter = ' ')]
    log2_memory_heights: Vec<usize>,
}

fn main() {
    // Setup logger.
    setup_logger();

    // Parse arguments.
    let args = Args::parse();

    // Load the maximal shapes, indexed by log shard size.
    let maximal_shapes: BTreeMap<usize, Vec<Shape<RiscvAirId>>> = serde_json::from_slice(
        &std::fs::read(&args.maximal_shapes_json).expect("failed to read maximal shapes"),
    )
    .expect("failed to deserialize maximal shapes");

    // For each maximal shape, generate all small shapes by varying the memory heights.
    let mut small_shapes = Vec::new();
    for (_, shapes) in maximal_shapes.iter() {
        for shape in shapes.iter() {
            for log2_memory_height in args.log2_memory_heights.iter() {
                let mut small_shape = shape.clone();
                small_shape.insert(RiscvAirId::MemoryGlobalInit, *log2_memory_height);
                small_shape.insert(RiscvAirId::MemoryGlobalFinalize, *log2_memory_height);

                let mut global_height = small_shape.height(&RiscvAirId::Global).unwrap();
                global_height += small_shape.height(&RiscvAirId::MemoryGlobalInit).unwrap();
                global_height += small_shape.height(&RiscvAirId::MemoryGlobalFinalize).unwrap();
                small_shape.insert(RiscvAirId::Global, log2_ceil_usize(global_height));

                small_shapes.push(small_shape);
            }
        }
    }

    // Serialize the small shapes.
    let serialized =
        serde_json::to_string(&small_shapes).expect("failed to serialize small shapes");
    std::fs::write("small_shapes.json", serialized).expect("failed to write small shapes");
}
