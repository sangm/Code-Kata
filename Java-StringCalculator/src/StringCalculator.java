import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class StringCalculator {
	public int add(String nums) {
		if (nums.length() == 0) return 0;
		String[] numbers = splitNumbers(nums);
		return sumNumbers(numbers);
	}

	private int sumNumbers(String[] numbers) {
		int sum = 0;
		for (String num : numbers) {
			int numToAdd = Integer.parseInt(num);
			if (numToAdd <= 1000)
				sum += Integer.parseInt(num);
		}
		return sum;
	}

	private String[] splitNumbers(String nums) {
		String delim = ",|\n";
		Pattern pattern = Pattern.compile("//\\[?([^\\]]+)\\]?\\n(.+)");
		Matcher matcher = pattern.matcher(nums);
		if (matcher.find()) {
			delim = Pattern.quote(matcher.group(1));
			nums = matcher.group(2);
		}
		String[] numbers = nums.split(delim);
		return numbers;
	}
}
