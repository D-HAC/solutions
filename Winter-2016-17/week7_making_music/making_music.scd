/**
 * Playing Scales in Supercollider
 * Author: Peter Gagliardi
 *
 * 1. Load this into a SuperCollider buffer
 * 2. Boot the server
 * 3. run one of the lines of code to select a scale
 * 4. Run the main block of code
 */

//Boot the server
s.boot;

//Set the root of the scale. MIDI note 60 is C5
~root = 60;

//========================================================
//Run ONE of the following lines of code to
//select a scale. These "scales" are really offsets in
//semitones. They will be added to the root MIDI note

//Major Scale (Ionian)
~pattern = [0, 2, 4, 5, 7, 9, 11, 12];

//Natural Minor Scale (Aeolian)
~pattern = [0, 2, 3, 5, 7, 8, 10, 12];

//Harmonic Minor Scale
~pattern = [0, 2, 3, 5, 7, 8, 11, 12];

//Dorian Scale
~pattern = [0, 2, 3, 5, 7, 9, 10, 12];

//Mixolydian Scale
~pattern = [0, 2, 4, 5, 7, 9, 10, 12];

//Phrygian Scale
~pattern = [0, 1, 4, 5, 7, 8, 10, 12];

//Lydian Scale
~pattern = [0, 2, 4, 6, 7, 9, 11, 12];

//Locrian Scale
~pattern = [0, 1, 3, 5, 6, 8, 10, 12];

//========================================================


//Run this block of code to play the scale
(
//Play the first and last notes a little longer than
//the middle notes
var durations = [0.5] ++ [0.25].stutter(6) ++ [0.5];
Pbind(
    //mirror makes the scale go up and down
    \dur, Pseq(durations.mirror, inf),
    \midinote, Pseq(~pattern.mirror + ~root, inf)
).play(quant: 1.0);
)