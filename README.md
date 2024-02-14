<h1 align="center"> 👨‍💻 ezCipher 👾  </h1>
<p align="center"> A simple CLI in C to encrypt and decrypt text using a variety of cipher algorithms. </p>


## 📜 Description 
__*"In cryptography, a cipher (or cypher) is an algorithm for performing encryption or decryption—a series of well-defined steps that can be followed as a procedure... 
ciphers generally substitute the same number of characters as are input."*__ ~ _Wikipedia_.

<br>

### The "Why" of this project

While going through [CS50x 2024's Problem Set 2](https://cs50.harvard.edu/x/2024/psets/2/), an idea clicked in my mind to code a Command-Line Tool that would take a Cipher algorithm, the way the user wishes to use it i.e. to choose between an Encryption/Decryption mode, take some text, process it as per the given requirements, and output the result. Simple enough, right?

And thus, I began working on this project, having in mind a similar objective.

<hr>

### Prerequisites

To use this program, a basic knowledge of ciphers would be a prerequisite.

Currently it features the below cipher algorithms:
  1. [Caesar](https://github.com/TERNION-1121/ezCipher/tree/main/cipher-descriptions/caesar.md)
  2. [Substitution](https://github.com/TERNION-1121/ezCipher/tree/main/cipher-descriptions/substitution.md)
  3. [Vigenère]()
  
Click on a cipher name to view its description/explanation.

### How to run the program?
__Requirements__: A C compiler, such as GCC or Clang.

1. Clone this repository
2. Open the terminal, and navigate to the repository `~/ezCipher`
3. Run the command `clang -o ec src/ec.c src/utils/utils.c src/ciphers/caesar.c src/ciphers/substitution.c src/ciphers/vigenere.c`
> You can also use `gcc` instead of `clang`
4. Run `./ec`
5. You'll be prompted with this message
```

error: incorrect number of arguments given, expected 4 -> 1

USAGE: ./ec <cipher> <encrypt/decrypt_mode> <key>

<cipher>:
        caesar
        substitution
        vigenere

<encrypt/decrypt_mode>:
        encrypt
        decrypt

<key>: in accordance with the opted cipher

```
.. You can either make use of the instructions given here, or follow along for a small example.

<br>

#### An example
1. Let's test the program by using `caesar` cipher with a key of value, say 2.
2. Run
```
./ec caesar encrypt 2
Hello, World!
This is ezCipher.
```
> Note: to end giving input, enter a newline and enter the EOF character (`Ctrl + Z` on Windows, `Ctrl + D` on Linux).
3. Output:
```
Jgnnq, Yqtnf!
Vjku ku gbEkrjgt.
```
4. Run
```
./ec caesar decrypt 2
Jgnnq, Yqtnf!
Vjku ku gbEkrjgt.
```
5. Output:
```
Hello, World!
This is ezCipher.
```

Voila! Now you know how to use ezCipher for encrypting and decrypting your texts!

<br>

To give some syntax on the program usage:

```
$ ./ec <cipher_algorithm_option> <encrypt_or_decrypt_mode> <KEY> 
<plaintext_spread_over_multiple_lines>
<EOF>
<processed_text>
```

Where,
```
<cipher_algorithm_option>
  caesar
  substitution
  vigenere

<encrypt_or_decrypt_mode>
  encrypt
  decrypt
  
<KEY>
  in accordance with the opted cipher
```

<hr>
<br>

## 🎯 Learnings
This was my first C Project that was spread over more than a single file! 

I learnt how to use header files to include content from different files into another. The code was written by me, with a side-quest to keep up with some common coding conventions.

I believe the code is well organised to some point. Let me know what I can do better with the code! (more about this in Contributions)

<br>

## ✏️ On Contributions
This marks the first release of `ezCipher`. 

I'd appreciate help in all forms, from beautifying the README or the code itself, to adding new cipher options!
Thanks for your kind attention!