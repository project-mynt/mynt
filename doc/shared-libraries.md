Shared Libraries
================

## myntconsensus

The purpose of this library is to make the verification functionality that is critical to Mynt's consensus available to other applications, e.g. to language bindings.

### API

The interface is defined in the C header `myntconsensus.h` located in  `src/script/myntconsensus.h`.

#### Version

`myntconsensus_version` returns an `unsigned int` with the API version *(currently at an experimental `0`)*.

#### Script Validation

`myntconsensus_verify_script` returns an `int` with the status of the verification. It will be `1` if the input script correctly spends the previous output `scriptPubKey`.

##### Parameters
- `const unsigned char *scriptPubKey` - The previous output script that encumbers spending.
- `unsigned int scriptPubKeyLen` - The number of bytes for the `scriptPubKey`.
- `const unsigned char *txTo` - The transaction with the input that is spending the previous output.
- `unsigned int txToLen` - The number of bytes for the `txTo`.
- `unsigned int nIn` - The index of the input in `txTo` that spends the `scriptPubKey`.
- `unsigned int flags` - The script validation flags *(see below)*.
- `myntconsensus_error* err` - Will have the error/success code for the operation *(see below)*.

##### Script Flags
- `myntconsensus_SCRIPT_FLAGS_VERIFY_NONE`
- `myntconsensus_SCRIPT_FLAGS_VERIFY_P2SH` - Evaluate P2SH ([BIP16](https://github.com/mynt/bips/blob/master/bip-0016.mediawiki)) subscripts
- `myntconsensus_SCRIPT_FLAGS_VERIFY_DERSIG` - Enforce strict DER ([BIP66](https://github.com/mynt/bips/blob/master/bip-0066.mediawiki)) compliance
- `myntconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY` - Enforce NULLDUMMY ([BIP147](https://github.com/mynt/bips/blob/master/bip-0147.mediawiki))
- `myntconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY` - Enable CHECKLOCKTIMEVERIFY ([BIP65](https://github.com/mynt/bips/blob/master/bip-0065.mediawiki))
- `myntconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY` - Enable CHECKSEQUENCEVERIFY ([BIP112](https://github.com/mynt/bips/blob/master/bip-0112.mediawiki))
- `myntconsensus_SCRIPT_FLAGS_VERIFY_WITNESS` - Enable WITNESS ([BIP141](https://github.com/mynt/bips/blob/master/bip-0141.mediawiki))

##### Errors
- `myntconsensus_ERR_OK` - No errors with input parameters *(see the return value of `myntconsensus_verify_script` for the verification status)*
- `myntconsensus_ERR_TX_INDEX` - An invalid index for `txTo`
- `myntconsensus_ERR_TX_SIZE_MISMATCH` - `txToLen` did not match with the size of `txTo`
- `myntconsensus_ERR_DESERIALIZE` - An error deserializing `txTo`
- `myntconsensus_ERR_AMOUNT_REQUIRED` - Input amount is required if WITNESS is used

### Example Implementations
- [NMynt](https://github.com/NicolasDorier/NMynt/blob/master/NMynt/Script.cs#L814) (.NET Bindings)
- [node-libmyntconsensus](https://github.com/bitpay/node-libmyntconsensus) (Node.js Bindings)
- [java-libmyntconsensus](https://github.com/dexX7/java-libmyntconsensus) (Java Bindings)
- [myntconsensus-php](https://github.com/Bit-Wasp/myntconsensus-php) (PHP Bindings)
