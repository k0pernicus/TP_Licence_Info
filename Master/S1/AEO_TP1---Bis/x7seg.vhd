----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:56:38 09/16/2014 
-- Design Name: 
-- Module Name:    x7seg - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity x7seg is
    Port ( sw : in  STD_LOGIC_VECTOR (3 downto 0);
			  e : in STD_LOGIC;
           sevenseg : out  STD_LOGIC_VECTOR (6 downto 0));
end x7seg;

architecture Behavioral of x7seg is

signal s : STD_LOGIC_VECTOR (4 downto 0);

begin

s(0) <= sw(0);
s(1) <= sw(1);
s(2) <= sw(2);
s(3) <= sw(3);
s(4) <= e;

with s select
sevenseg <=
            "1000000" when "10000" ,
            "1111001" when "10001" ,
            "0100100" when "10010" ,
            "0110000" when "10011" ,
            "0011001" when "10100" ,
            "0010010" when "10101" ,
            "0000010" when "10110" ,
            "1111000" when "10111" ,
            "0000000" when "11000" ,
            "0010000" when "11001" ,
            "0001000" when "11010" ,
            "0000011" when "11011" ,
            "1000110" when "11100" ,
            "0100001" when "11101" ,
            "0000110" when "11110" ,
				"0001110" when "11111" ,
            "1111111" when others;

end Behavioral;

