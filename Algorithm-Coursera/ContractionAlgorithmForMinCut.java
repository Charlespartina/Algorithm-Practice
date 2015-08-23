import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * This is a randomized contraction algorithm for the min cut problem.
 * @author Tang
 */
  
public class ContractionAlgorithmForMinCut {
	public class Vertex{
		int label;
		ArrayList<Integer> adjPoint = new ArrayList<Integer>();
		public Vertex(int label, ArrayList<Integer> adjPoint){
			this.label = label;
			this.adjPoint = adjPoint;
		}
	}
	public static int FindMinCut(ArrayList<Vertex> vertices){
		int a = 0;
		int b = 1;
		while (vertices.size() > 2){
			int firstIndex = (int)(Math.random() * vertices.size());
			int secondIndex = 0;
			int randomIndex = (int)(Math.random() * vertices.get(firstIndex).adjPoint.size());
			int secondLabel = vertices.get(firstIndex).adjPoint.get(randomIndex);
			for (int i = 0; i < vertices.size(); i++){
				if (vertices.get(i).label == secondLabel){
					secondIndex = i;
					break;
				}
			}
			
			Contraction(firstIndex, secondIndex, vertices);
			System.out.println("There are vertices: " + vertices.size());
			
			// Result
			a = vertices.get(0).adjPoint.size();
			b = vertices.get(1).adjPoint.size();
			System.out.println("There are crossing edges: "+ a + " "+ b);
			
		}
		if (a == b){
			return a;
		}
		else{
			return -1;
		}
	}
	
	public static void Contraction(int first, int second, ArrayList<Vertex> vertices){
		
		// Change the first vertex and remove the second vertex
		ArrayList<Integer> adjOfFirst = vertices.get(first).adjPoint;
		ArrayList<Integer> adjOfSecond = vertices.get(second).adjPoint;
		int firstLabel = vertices.get(first).label;
		int secondLabel = vertices.get(second).label;
		
		for (int i = 0; i < adjOfSecond.size(); i++){
				adjOfFirst.add(adjOfSecond.get(i)); // Add a label from second list to the first list
				
				// Change the data of vertices that the second vertex pointed to
				for (int j = 0; j < vertices.size(); j ++){
					if (vertices.get(j).label == adjOfSecond.get(i)){
						
						vertices.get(j).adjPoint.add(firstLabel); // Add the label of the first to this vertex
						
						for (int t = 0; t < vertices.get(j).adjPoint.size(); t++){
							if (vertices.get(j).adjPoint.get(t) == secondLabel){
								
								vertices.get(j).adjPoint.remove(t);
								
								break;
							}
							
						}
						break;
					}	
				}
		}
		for (int i = 0; i < adjOfFirst.size(); i++){
			if (adjOfFirst.get(i).equals(firstLabel)){
				adjOfFirst.remove(i);
				
				i--;
			}
		}
		vertices.remove(second);
	}
	
	
	public static void main(String args[]){
		
		// Construct the representation of the graph
		ArrayList<Vertex> vertices = new ArrayList<Vertex>();
		ContractionAlgorithmForMinCut c = new ContractionAlgorithmForMinCut();
		
		try {
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			while(fileScanner.hasNext()){
				String line = fileScanner.nextLine();
				String[] chars = line.split("\\s+");
				int newLabel = 0;
				ArrayList<Integer> newList = new ArrayList<Integer>();
				for (int i = 0; i < chars.length; i++){
					
					if (i == 0){
						newLabel = Integer.parseInt(chars[i]);
					}else{
						newList.add(Integer.parseInt(chars[i]));
					}
					
				}
				Vertex newVer = c.new Vertex(newLabel, newList);
				vertices.add(newVer);
				
			}
			fileScanner.close();
			
		}
		catch(Exception e){
			System.err.println("ERROR");
			e.printStackTrace();
		}
		
			// Contraction for once
			FindMinCut(vertices);
    }	
	
}
