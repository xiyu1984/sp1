use serde::{Deserialize, Serialize};

use crate::Opcode;

use super::{create_random_lookup_ids, LookupId, MemoryRecordEnum};

/// Alu Instruction Event.
///
/// This object encapsulated the information needed to prove a RISC-V ALU operation.
#[derive(Debug, Clone, Copy, Serialize, Deserialize)]
#[repr(C)]
pub struct AluEvent {
    /// The program counter.
    pub pc: u32,
    /// The lookup identifier.
    pub lookup_id: LookupId,
    /// The opcode.
    pub opcode: Opcode,
    /// The first operand value.
    pub a: u32,
    /// The second operand value.
    pub b: u32,
    /// The third operand value.
    pub c: u32,
    /// Whether the first operand is register 0.
    pub op_a_0: bool,
    /// The result of the operation in the format of [``LookupId``; 6]
    pub sub_lookups: [LookupId; 6],
}

impl AluEvent {
    /// Create a new [`AluEvent`].
    #[must_use]
    pub fn new(pc: u32, opcode: Opcode, a: u32, b: u32, c: u32, op_a_0: bool) -> Self {
        Self {
            pc,
            lookup_id: LookupId::default(),
            opcode,
            a,
            b,
            c,
            op_a_0,
            sub_lookups: create_random_lookup_ids(),
        }
    }
}

/// Memory Instruction Event.
///
/// This object encapsulated the information needed to prove a RISC-V memory operation.
#[derive(Debug, Clone, Copy, Serialize, Deserialize)]
#[repr(C)]
pub struct MemInstrEvent {
    /// The shard.
    pub shard: u32,
    /// The clk.
    pub clk: u32,
    /// The program counter.
    pub pc: u32,
    /// The opcode.
    pub opcode: Opcode,
    /// The first operand value.
    pub a: u32,
    /// The second operand value.
    pub b: u32,
    /// The third operand value.
    pub c: u32,
    /// Whether the first operand is register 0.
    pub op_a_0: bool,
    /// The memory access record for memory operations.
    pub mem_access: MemoryRecordEnum,
    /// The memory add lookup id.
    pub memory_add_lookup_id: LookupId,
    /// The memory sub lookup id.
    pub memory_sub_lookup_id: LookupId,
}

impl MemInstrEvent {
    /// Create a new [`MemInstrEvent`].
    #[must_use]
    #[allow(clippy::too_many_arguments)]
    pub fn new(
        shard: u32,
        clk: u32,
        pc: u32,
        opcode: Opcode,
        a: u32,
        b: u32,
        c: u32,
        op_a_0: bool,
        mem_access: MemoryRecordEnum,
        memory_add_lookup_id: LookupId,
        memory_sub_lookup_id: LookupId,
    ) -> Self {
        Self {
            shard,
            clk,
            pc,
            opcode,
            a,
            b,
            c,
            op_a_0,
            mem_access,
            memory_add_lookup_id,
            memory_sub_lookup_id,
        }
    }
}

/// Branch Instruction Event.
///
/// This object encapsulated the information needed to prove a RISC-V branch operation.
#[derive(Debug, Clone, Copy, Serialize, Deserialize)]
#[repr(C)]
pub struct BranchEvent {
    /// The program counter.
    pub pc: u32,
    /// The next program counter.
    pub next_pc: u32,
    /// The opcode.
    pub opcode: Opcode,
    /// The first operand value.
    pub a: u32,
    /// The second operand value.
    pub b: u32,
    /// The third operand value.
    pub c: u32,
    /// Whether the first operand is register 0.
    pub op_a_0: bool,
    /// The branch gt lookup id.
    pub branch_gt_lookup_id: LookupId,
    /// The branch lt lookup id.
    pub branch_lt_lookup_id: LookupId,
    /// The branch add lookup id.
    pub branch_add_lookup_id: LookupId,
}

impl BranchEvent {
    /// Create a new [`BranchEvent`].
    #[must_use]
    #[allow(clippy::too_many_arguments)]
    pub fn new(
        pc: u32,
        next_pc: u32,
        opcode: Opcode,
        a: u32,
        b: u32,
        c: u32,
        op_a_0: bool,
        branch_gt_lookup_id: LookupId,
        branch_lt_lookup_id: LookupId,
        branch_add_lookup_id: LookupId,
    ) -> Self {
        Self {
            pc,
            next_pc,
            opcode,
            a,
            b,
            c,
            op_a_0,
            branch_gt_lookup_id,
            branch_lt_lookup_id,
            branch_add_lookup_id,
        }
    }
}

/// Jump Instruction Event.
///
/// This object encapsulated the information needed to prove a RISC-V jump operation.
#[derive(Debug, Clone, Copy, Serialize, Deserialize)]
#[repr(C)]
pub struct JumpEvent {
    /// The program counter.
    pub pc: u32,
    /// The next program counter.
    pub next_pc: u32,
    /// The opcode.
    pub opcode: Opcode,
    /// The first operand value.
    pub a: u32,
    /// The second operand value.
    pub b: u32,
    /// The third operand value.
    pub c: u32,
    /// Whether the first operand is register 0.
    pub op_a_0: bool,
    /// The jump jal lookup id.
    pub jump_jal_lookup_id: LookupId,
    /// The jump jalr lookup id.
    pub jump_jalr_lookup_id: LookupId,
}

impl JumpEvent {
    /// Create a new [`JumpEvent`].
    #[must_use]
    #[allow(clippy::too_many_arguments)]
    pub fn new(
        pc: u32,
        next_pc: u32,
        opcode: Opcode,
        a: u32,
        b: u32,
        c: u32,
        op_a_0: bool,
        jump_jal_lookup_id: LookupId,
        jump_jalr_lookup_id: LookupId,
    ) -> Self {
        Self { pc, next_pc, opcode, a, b, c, op_a_0, jump_jal_lookup_id, jump_jalr_lookup_id }
    }
}
/// AUIPC Instruction Event.
///
/// This object encapsulated the information needed to prove a RISC-V AUIPC operation.
#[derive(Debug, Clone, Copy, Serialize, Deserialize)]
#[repr(C)]
pub struct AUIPCEvent {
    /// The program counter.
    pub pc: u32,
    /// The opcode.
    pub opcode: Opcode,
    /// The first operand value.
    pub a: u32,
    /// The second operand value.
    pub b: u32,
    /// The third operand value.
    pub c: u32,
    /// Whether the first operand is register 0.
    pub op_a_0: bool,
    /// The AUIPC add lookup id.
    pub auipc_nonce: LookupId,
}

impl AUIPCEvent {
    /// Create a new [`AUIPCEvent`].
    #[must_use]
    pub fn new(
        pc: u32,
        opcode: Opcode,
        a: u32,
        b: u32,
        c: u32,
        op_a_0: bool,
        auipc_nonce: LookupId,
    ) -> Self {
        Self { pc, opcode, a, b, c, op_a_0, auipc_nonce }
    }
}
