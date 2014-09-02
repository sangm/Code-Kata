import static org.junit.Assert.*;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.junit.Test;


public class StringCalculatorTest {

	StringCalculator calc = new StringCalculator();
	
	@Test public void test_Empty_String_Returns_Zero() {
		assertEquals(0, calc.add(""));
	}
	
	@Test public void test_One_String_Returns_Number() {
		assertEquals(1, calc.add("1"));
		assertEquals(2, calc.add("2"));
		assertEquals(3, calc.add("3"));
		assertEquals(4, calc.add("4"));
	}
	
	@Test public void test_Two_Strings_Returns_Sum() {
		assertEquals(3, calc.add("1,2"));
		assertEquals(4, calc.add("2,2"));
		assertEquals(5, calc.add("3,2"));
		assertEquals(6, calc.add("4,2"));
		assertEquals(10, calc.add("5,5"));
		assertEquals(12, calc.add("6,6"));
		assertEquals(20, calc.add("18,2"));
	}
	
	@Test public void test_Unknown_Strings_Returns_Sum() {
		assertEquals(20, calc.add("14,2,2,2"));
		assertEquals(20, calc.add("10,2,5,1,1,1"));
		assertEquals(10, calc.add("1,1,1,1,1,1,1,1,1,1"));
	}
	
	@Test public void test_Handles_Newline_Character() {
		assertEquals(3, calc.add("1\n1,1"));
	}
	
	@Test public void test_Changing_Delimiters() {
		assertEquals(3, calc.add("//;\n1;1;1"));
		assertEquals(5, calc.add("//;\n3;2"));
		assertEquals(5, calc.add("//'\n3'2"));
		assertEquals(5, calc.add("//>\n3>2"));
		assertEquals(5, calc.add("//*\n3*2"));
	}
	
	@Test public void test_Ignores_Numbers_Greater_Than_1000() {
		assertEquals(1001, calc.add("1,1000"));
		assertEquals(4, calc.add("1,3000,2,1010,1"));
		assertEquals(10, calc.add("10,10000"));
	}
	
	@Test public void test_Different_Length_Delimiters() {
		assertEquals(6, calc.add("//[***]\n1***2***3"));
	}
	
	@Test public void test_Regex_API_Different_Length_Delimiters() {
		String exampleString = "//[***]\n1***2***3";
		Pattern pattern = Pattern.compile("//\\[?([^\\]]+)\\]?\\n(.+)");
		Matcher matcher = pattern.matcher(exampleString);
		assertTrue(matcher.find());
		assertEquals("***", matcher.group(1));
		assertEquals("1***2***3", matcher.group(2));
	}
	
	@Test public void test_Regex_API_Multiple_Delimiters() {
		String exampleString = "//[*][%]\n1*2%3";
		Pattern pattern = Pattern.compile("//(\\[.\\])+");
		Matcher matcher = pattern.matcher(exampleString);
		assertTrue(matcher.find());
		System.out.println("Matched: " + matcher.group());
		System.out.println("Matched: " + matcher.group(1));
		System.out.println("Matched: " + matcher.group(1));
	}

}
