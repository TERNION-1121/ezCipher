# Caesar

<img src="https://cs50.harvard.edu/x/2024/psets/2/caesar/cipher.jpg" height=300 width=300>

<br>

_"The Caesar Cipher, used by Julius Caesar around 58 BC, is a substitution cipher that **shifts** letters in a message to make it unreadable if intercepted. To decrypt, the receiver reverses the shift."_[^1]

<hr>
<br>

For instance, let's showcase the usage of caesar on `Hello, World` with a shift/key of value, say 4.

| plaintext   | H | e | l | l | o | , |   | W | o | r | l | d | 
|-------------|---|---|---|---|---|---|---|---|---|---|---|---|
|     +key    | 4 | 4 | 4 | 4 | 4 | 0 | 0 | 4 | 4 | 4 | 4 | 4 |
| =ciphertext | L | i | p | p | s | , |   | A | s | v | p | h |

<br>

Notice how non-alphabetical characters remain as it is in the ciphertext.

Also, when the resultant shifted character is at a position greater than **26**, as we see in the case of encrypting `W` which is at the position **23** in the alphabet, we perform the following calculation to get the resultant ciphertext character:

$$ c_i = (p_i + shift) \ \% \ 26 $$

You can interpret this using the above given image, i.e. the character at position **23 + 4 = 27** is the same as the character at position **1**, that is `A`. It sort of gets rotated to the same range of characters $[1, 26]$ .

<br>

Decryption is just shifting the characters with the given shift/key backwards,

| ciphertext  | L | i | p | p | s | , |   | A | s | v | p | h | 
|-------------|---|---|---|---|---|---|---|---|---|---|---|---|
|     -key    | 4 | 4 | 4 | 4 | 4 | 0 | 0 | 4 | 4 | 4 | 4 | 4 |
|  =plaintext | H | e | l | l | o | , |   | W | o | r | l | d |

<br>

Using the formula, $p_i = (c_i + 26 - shift) \ \% \ 26$


[^1]: Source: [Khan Academy](https://www.khanacademy.org/computing/computer-science/cryptography/crypt/v/caesar-cipher#:~:text=The%20Caesar%20Cipher%2C%20used%20by,exploits%20patterns%20in%20letter%20frequencies.)
