# Patched Crates

We maintain forks of commonly used libraries in blockchain infrastructure to significantly accelerate the execution of certain operations.
Under the hood, we use [precompiles](./precompiles.md) to achieve tremendous performance improvements in proof generation time.

**If you know of a library or library version that you think should be patched, please open an issue or a pull request!**

## Supported Libraries

| Crate Name          | Repository                                                                            | Notes            |
| ------------------- | ------------------------------------------------------------------------------------- | ---------------- |
| sha2                | [sp1-patches/RustCrypto-hashes](https://github.com/sp1-patches/RustCrypto-hashes)     | sha256           |
| sha3                | [sp1-patches/RustCrypto-hashes](https://github.com/sp1-patches/RustCrypto-hashes)     | keccak256        |
| bigint              | [sp1-patches/RustCrypto-bigint](https://github.com/sp1-patches/RustCrypto-bigint)     | bigint           |
| tiny-keccak         | [sp1-patches/tiny-keccak](https://github.com/sp1-patches/tiny-keccak)                 | keccak256        |
| ed25519-consensus   | [sp1-patches/ed25519-consensus](http://github.com/sp1-patches/ed25519-consensus)      | ed25519 verify   |
| curve25519-dalek-ng | [sp1-patches/curve25519-dalek-ng](https://github.com/sp1-patches/curve25519-dalek-ng) | ed25519 verify   |
| curve25519-dalek    | [sp1-patches/curve25519-dalek](https://github.com/sp1-patches/curve25519-dalek)       | ed25519 verify   |
| ecdsa-core          | [sp1-patches/signatures](http://github.com/sp1-patches/signatures)                    | secp256k1 verify |
| secp256k1           | [sp1-patches/rust-secp256k1](http://github.com/sp1-patches/rust-secp256k1)            | secp256k1 verify |

## Using Patched Crates

To use the patched libraries, you can use corresponding patch entries in your program's `Cargo.toml` such as:

```toml
[patch.crates-io]
sha2-v0-9-8 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha2", branch = "patch-sha2-v0.9.8" }
sha2-v0-10-6 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha2", branch = "patch-sha2-v0.10.6" }
sha2-v0-10-8 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha2", branch = "patch-sha2-v0.10.8" }
sha3-v0-9-8 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha3", branch = "patch-sha3-v0.9.8" }
sha3-v0-10-6 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha3", branch = "patch-sha3-v0.10.6" }
sha3-v0-10-8 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha3", branch = "patch-sha3-v0.10.8" }
crypto-bigint = { git = "https://github.com/sp1-patches/RustCrypto-bigint", branch = "patch-v0.5.5" }
tiny-keccak = { git = "https://github.com/sp1-patches/tiny-keccak", branch = "patch-v2.0.2" }
curve25519-dalek = { git = "https://github.com/sp1-patches/curve25519-dalek", branch = "patch-curve25519-v4.1.3" }
curve25519-dalek-ng = { git = "https://github.com/sp1-patches/curve25519-dalek-ng", branch = "patch-v4.1.1" }
ed25519-consensus = { git = "https://github.com/sp1-patches/ed25519-consensus", branch = "patch-v2.1.0" }
ecdsa-core = { git = "https://github.com/sp1-patches/signatures", package = "ecdsa", branch = "patch-ecdsa-v0.16.9" }
secp256k1 = { git = "https://github.com/sp1-patches/rust-secp256k1", branch = "patch-v0.29.0" }
```

If you are patching a crate from Github instead of from crates.io, you need to specify the
repository in the patch section. For example:

```toml
[patch."https://github.com/RustCrypto/hashes"]
sha3 = { git = "https://github.com/sp1-patches/RustCrypto-hashes", package = "sha3", branch = "patch-sha3-v0.10.8" }
```

An example of using patched crates is available in our [Tendermint Example](https://github.com/succinctlabs/sp1/blob/main/examples/tendermint/program/Cargo.toml#L22-L25).

## Ed25519 Acceleration

To accelerate Ed25519 operations, you'll need to patch crates depending on if you're using the `ed25519-consensus` or `ed25519-dalek` library in your program or dependencies.

Generally, `ed25519-consensus` has better performance than `ed25519-dalek` by a factor of 2.

### Patches

Apply the following patches based on what crates are in your dependencies.

- `ed25519-consensus`

  ```toml
  ed25519-consensus = { git = "https://github.com/sp1-patches/ed25519-consensus", branch = "patch-v2.1.0" }
  ```

  Note: The curve operations for Ed25519 occur mainly inside of `curve25519-dalek-ng`, but the crate also exposes
  a `u32_backend` feature flag which accelerates signature recovery by 10% over the default `u64_backend`, which is why
  `ed25519-consensus` is patched rather than `ed25519-dalek`.

- `ed25519-dalek`

  ```toml
  curve25519-dalek = { git = "https://github.com/sp1-patches/curve25519-dalek", branch = "patch-curve25519-v4.1.3" }
  ```

  Note: The curve operations occur inside of the `curve25519-dalek` crate.

- `curve25519-dalek`
  ```toml
  curve25519-dalek = { git = "https://github.com/sp1-patches/curve25519-dalek-ng", branch = "patch-v4.1.3" }
  ```

## Secp256k1 Acceleration

To accelerate Secp256k1 operations, you'll need to patch `k256` or `secp256k1` depending on your usage.

Generally, if a crate you're using (ex. `revm`) has support for using `k256` instead of `secp256k1`, you should use `k256`.

### Patches

Apply the following patches based on what crates are in your dependencies.

- `k256`

  ```toml
  ecdsa-core = { git = "https://github.com/sp1-patches/signatures", package = "ecdsa", branch = "patch-ecdsa-v0.16.9" }
  ```

  Note: The curve operations for `k256` are inside of the `ecdsa-core` crate, so you don't need to patch `k256` itself, and just patching `ecdsa-core` is enough.

- `secp256k1`
  ```toml
  secp256k1 = { git = "https://github.com/sp1-patches/rust-secp256k1", branch = "patch-v0.29.0" }
  ```

## Troubleshooting

### Verifying Patch Usage: Cargo

You can check if the patch was applied by using cargo's tree command to print the dependencies of the crate you patched.

```bash
cargo tree -p sha2@0.9.8
```

Next to the package name, it should have a link to the Github repository that you patched with.

Ex.

```
sha2 v0.9.8 (https://github.com/sp1-patches/RustCrypto-hashes?branch=patch-sha2-v0.9.8#afdbfb09)
├── ...
```

### Verifying Patch Usage: SP1

To check if a precompile is used by your program, you can view SP1's ExecutionReport, which is returned when executing a program with `execute`. In `ExecutionReport` you can view the `syscall_counts` map to view if a specific syscall was used.

For example, if you wanted to check `sha256` was used, you would look for `SHA_EXTEND` and `SHA_COMPRESS` in `syscall_counts`.

An example of this is available in our [Patch Testing Example](https://github.com/succinctlabs/sp1/blob/dd032eb23949828d244d1ad1f1569aa78155837c/examples/patch-testing/script/src/main.rs).

### Cargo Version Issues

If you encounter issues with version commits on your patches, you should try updating the patched crate manually.

```bash
cargo update -p <patch-crate-name>
```

If you encounter issues relating to cargo / git, you can try setting `CARGO_NET_GIT_FETCH_WITH_CLI`:

```bash
CARGO_NET_GIT_FETCH_WITH_CLI=true cargo update -p <patch-crate-name>
```

You can permanently set this value in `~/.cargo/config`:

```toml
[net]
git-fetch-with-cli = true
```
