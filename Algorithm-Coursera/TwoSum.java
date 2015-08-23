import java.io.File;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

/**
 * This TwoSum algorithm computes the number of target values t in the interval [-10000,10000] (inclusive) 
 * such that there are distinct numbers x,y in the input file that satisfy x+y=t.
 * @author Tang
 *
 */
public class TwoSum {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int counter = 0;
		ArrayList<Long> ref = new ArrayList<Long>();
		HashSet<Long> container = new HashSet<Long>();
		HashSet<Long> target = new HashSet<Long>();
		try {
			
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			while(fileScanner.hasNext()){
				String line = fileScanner.nextLine();
				Long num = Long.parseLong(line);
				ref.add(num);
				container.add(num);
			}
			fileScanner.close();
			
		}
		catch (Exception e){
			System.err.println("Err");
		}
		for (int i = 0; i < ref.size(); i++){
			for (int t = -10000 ; t <= 10000; t++){
				if (target.contains(t)){
					continue;
				}
				Long y = t - ref.get(i);
				if(y != ref.get(i) && container.contains(y)){
					if(target.contains(ref.get(i) + y)){
						
					}
					else{
						target.add(ref.get(i) + y);
						counter++;
						System.out.println(counter);
					}
				}
				
			}	
		}
		System.out.println(counter);
	}

}
