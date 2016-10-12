with Ada.Text_IO.Unbounded_IO; use Ada.Text_IO.Unbounded_IO;
with Ada.Strings.Unbounded; use Ada.Strings.Unbounded;

procedure Disemvoweler is

Input : Unbounded_String := To_Unbounded_String ("Hello World!");

Vowels : Unbounded_String;      -- Is empty by default.
Consonants : Unbounded_String;  -- Is empty by default.
Spaces : Unbounded_String;      -- Is empty by default.

begin
	for J in 1 .. Length (Input) loop
		case Element (Input, J) is
		      when 'a' =>
			  Append (Vowels, 'a');
		      when 'e' =>
			  Append (Vowels, 'e');
		      when 'i' =>
			  Append (Vowels, 'i');
		      when 'o' =>
			  Append (Vowels, 'o');
		      when 'u' =>
			  Append (Vowels, 'u');
		      when ' ' =>
			  Append (Spaces, ' ');
		      when others =>
			  Append (Consonants, Element (Input, J));
		   end case;
   	end loop;
	Put_Line (Consonants);
	Put_Line (Vowels);

end Disemvoweler;
