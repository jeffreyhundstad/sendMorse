/* Take a String and convert it to morse code.
 * FIXME: only knows alpha and digits
 * Requires dit(), dah() and morseDelay() fuctions to
 *   already be defined.
 * Example: sendMorse("cq de we0a k");
 *
 * By: Jeffrey Hundstad <we0a@arrl.net>
 */
void sendMorse(String morse_word) {

  Serial.println("Send Morse: " + morse_word);

  // Define all the morse letters a-z
  static String morse_letters[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--.."
  };

  // Define all the morse digits 0-9
  static String morse_digits[] = {
    "-----",
    ".----",
    "..---",
    "...--",
    "....-",
    ".....",
    "-....",
    "--...",
    "--...",
    "---..",
    "----."
  };

  /* 1. Go through the incoming word, one letter at a time.
   * 2. Decode that letter into "." dit, "-" dah, or " " morse_delay
   * 3. Go through each of the dit and dah for each letter that was converted,
   *    and call the corect dit(), dah() or morse_delay() function.
   */

  // 1. Go through the incoming word, one letter at a time.
  for (int letter = 0; letter <= morse_word.length(); letter++) {
    char current = morse_word[letter];
    String morse_decoded;

    // 2. Decode that letter into "." dit, "-" dah, or " " morse_delay
    //    Look up letters and digits from our table.
    if ((current >= 'a') && (current <= 'z'))
      morse_decoded = morse_letters[current - 'a']; // table lookup
    else if ((current >= '0') && (current <= '9'))
      morse_decoded = morse_digits[current - '0']; // table lookup
    else
      morse_decoded = " ";

    //  3. Go through each of the dit and dah for each letter that was converted,
    //     and call the corect dit(), dah() or morse_delay() function.
    Serial.println("Sending morse: " + morse_decoded);
    for (int dit_dah = 0; dit_dah <= morse_decoded.length(); dit_dah++) {
      switch (morse_decoded[dit_dah]) {
        case '.':
          dit();
          break;
        case '-':
          dah();
          break;
        default:
          // This shouldn't be possible.
          morse_delay();
          break;
      }
    }
  }
}

