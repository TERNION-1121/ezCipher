# ezCipher
A CLI in C/C++ to encrypt and decrypt text using a variety of cipher algorithms

#### Supposed Working:
```bash
$ ./ec -<cipher_algorithm_option> -<encrypt_or_decrypt_mode> <KEY> 
$ <plaintext_spread_over_multiple_lines>
$ <end_taking_user_input_when_EOF_encountered>
$ encrypted/decrypted cipher/plain text:
$ <cipher_text>
```

Where,
```
<cipher_algorithm_option>
  c: caesar
  s: substitution
<encrypt_or_decrypt_mode>
  e: encrypt
  d: decrypt
<KEY>
  In accordance with the opted cipher
```

#### TODOs
1. Add Options for Caesar and Substitution Cipher (simple enough?)
