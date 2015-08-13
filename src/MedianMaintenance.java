import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * The goal of this problem is to implement the "Median Maintenance" algorithm
 * and compute the sum of medians when each element is scanned.
 * @author Tang
 *
 */
public class MedianMaintenance {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int sum = 0;
		PriorityQueue<Integer> high = new PriorityQueue<Integer>(10);
		PriorityQueue<Integer> low = new PriorityQueue<>(10, Collections.reverseOrder());
		try {
			
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			while(fileScanner.hasNext()){
				String line = fileScanner.nextLine();
				Integer num = Integer.parseInt(line);
				if (high.size() == 0 && low.size() == 0){
					high.add(num);
					sum += num;
					System.out.println(num);
					continue;
				}
				if (num >= high.peek()){
					high.add(num);
				}
				else{
					low.add(num);
				}
				if (high.size() - low.size() >= 2){
					low.add(high.poll());
				}
				if (low.size() - high.size() >= 2){
					high.add(low.poll());
				}
				int median = 0;
				
				if ((high.size() + low.size()) % 2 == 0){
					median = low.peek();
				}
				else{
					median = high.size() > low.size() ? high.peek() : low.peek();
				}
				sum += median;
				System.out.println(median);
				
			}
			fileScanner.close();
			
		}
		catch(Exception e){
			
		}
		System.out.println("Sum: " + sum);
		System.out.println(sum % 10000);
	}

}
