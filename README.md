# buzzwire_adv
A buzzwire game for Arduino with scoring &amp; LCD display.  Timer counts down and each wire touch results in a penalty.

Using a bare 12 gauge wire for the wire course and a small eye bolt for the loop.

See photos for reference.

Build tips:

* Mount start button at edge of breadboard so the loop can touch it to start.  This allows the timer to begin at the correct time.
This avoids the situation where you start with one finger and go with the other, leading to less accurate scoring.

Recommended order of soldering:
1. Diode to 12 gauge copper wire
2. Bend the copper wire to roughly the design you want.
2. Copper wire to start ring terminal
3. Diode to the end ring terminal.

I recommend you keep the start and end copper wire straight and perpendicular to the board.

I used ring terminals for start, end, and loop wire connections to the wood board. 
After soldering to the terminals, I bend them 90 degrees needle nose pliers.
* For the starting copper wire, I crimped the terminal to the wire, and added solder to secure the connection. (make sure the loop can touch the start button)
* For the ending copper wire, I soldered the diode in place, and wrapped with heat shrink and/or electrical tape.
* For the other end of the diode, I soldered the diode to the ring terminal and wrapped with heat shrink and/or electrical tape

Breadboard connections were made by stripping the end of a jumper cable, wrapping it around the screw, and sandwiching between the ring terminal and a washer.

Screws were used to gently hold the broadboard in place on the wood board.
Finishing nails are used to anchor the Arduino board in place so it doesn't move while plugging and unplugging the power or USB cable.

