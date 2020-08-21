library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;


entity shifter_v4 is
port ( clk_i : in std_logic;
	  entrada_i : in std_logic_vector(31 downto 0) ; --input
	  shift_i : in std_logic_vector(31 downto 0) ; --input
	  direccion_i : in std_logic_vector(31 downto 0) ; --input
	  salida_o : out std_logic_vector(31 downto 0) --output
      );
end entity shifter_v4 ;

architecture behv of shifter_v4 is
signal sentido : std_logic;
begin

process(clk_i, shift_i) -- input vectors 
begin
  
  if rising_edge (clk_i) then		
			
			if(direccion_i = "00000000000000000000000000000000") then
			salida_o <= std_logic_vector((SHL(unsigned(entrada_i), unsigned(shift_i))));
			else salida_o <= std_logic_vector((SHR(unsigned(entrada_i), unsigned(shift_i))));
			end if;
end if;    
end process;
end behv;
