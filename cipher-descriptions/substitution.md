# Substitution

<img src="https://github.com/TERNION-1121/ezCipher/assets/97667653/7dcd24ce-4f1c-4ab9-824f-d57df644f54e" width=640 height=360>

<br>
<br>

In substitution cipher, we encrypt our message by replacing each letter with another one. To do this we require a mapping of all the characters of the alphabet to some other character. A **key** fulfils this purpose. 

The key is a 26 character long valid permutation of the alphabet. Where the $i^{th}$ character in the alphabet is replaced with the $i^{th}$ character in the **key** to encrypt our message.

To decrypt, we reverse this process, which can only be done with the help of the same key which was earlier used to encrypt. For every character, say $c$, in the cipher text, we replace it with the character
that occurs at the same position in the alphabet, as $c$ did in the key. So if $c$ is present at the $i^{th}$ position in the key, we replace it with the $i^{th}$ character of the alphabet.

<hr>
<br>

For instance, let's encrypt `Hello, World!` using substitution cipher. Let $key$ = `NAHQXROVEKUZIBCLWYTDMSFGJP`

#### Mapping

| A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| N | A | H | Q | X | R | O | V | E | K | U | Z | I | B | C | L | W | Y | T | D | M | S | F | G | J | P |

<br>
<br>

| plaintext   | H | e | l | l | o | , |   | W | o | r | l | d | 
|-------------|---|---|---|---|---|---|---|---|---|---|---|---|
| =ciphertext | V | x | z | z | c | , |   | F | c | y | z | q |

<br>

Notice how non-alphabetical characters remain as it is in the ciphertext.

Decryption is just reversing the process, as discussed above.

<br>

| plaintext   | V | x | z | z | c | , |   | F | c | y | z | q |
|-------------|---|---|---|---|---|---|---|---|---|---|---|---|
| =ciphertext | H | e | l | l | o | , |   | W | o | r | l | d | 