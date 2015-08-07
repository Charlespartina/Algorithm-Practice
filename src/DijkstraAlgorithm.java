import java.io.File;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

/**
 * This Dijkstra Algorithm (undirected version) serves to compute shortest path from a source vertex to 
 * all other vertices.
 * @author Tang
 *
 */

public class DijkstraAlgorithm {
	public static final int num = 200;
	private class Vertex{
		private int label = 0;
		private ArrayList<Integer[]> neighbor;
		private Integer score;
		public Vertex(int label, ArrayList<Integer[]> neighbor){
			this.label = label;
			this.neighbor = neighbor;
			this.score = 1000000;
		}
		
	}
	public class VertexComparator implements Comparator<Vertex>{
		public int compare(Vertex a, Vertex b){
			if(a.score < b.score){
				return -1;
			}
			else if (a.score == b.score){
				return 0;
			}
			else{
				return 1;
			}
		}
	}
	public Integer[] HeapDijkstra(Vertex[] vertices, Vertex source){
		VertexComparator order = new VertexComparator();
		ArrayList<Vertex> processed = new ArrayList<Vertex>();
		Integer[] distances = new Integer[num + 1];
		
		
		while (processed.size() != vertices.length - 1){
			System.out.println("Size"+processed.size());
			System.out.println("Length"+ (vertices.length - 1));
			if (processed.size() == 0){
				processed.add(source);
				source.score = 0;
				distances[1] = source.score;
				System.out.println("Source");
			}
			else{
				System.out.println("NEXT");
				PriorityQueue<Vertex> tmp = new PriorityQueue<Vertex>(11,order);
				for (int i = 0; i < processed.size(); i++){
					Vertex current = processed.get(i);
					System.out.println("CUR" + current.label);
					for (int j = 0; j < current.neighbor.size(); j++){
						int label = current.neighbor.get(j)[0];
						int length = current.neighbor.get(j)[1];
						if (! processed.contains(vertices[label])){
							System.out.println("Neighbor"+label);
							int newscore = current.score + length;
							System.out.println("New Score"+newscore);
							if (vertices[label].score == 1000000){
								vertices[label].score = newscore;
								tmp.add(vertices[label]);
								System.out.println("Add");
							}
							else if ( newscore < vertices[label].score){
								tmp.remove(vertices[label]);
								vertices[label].score = newscore;
								tmp.add(vertices[label]);
								System.out.println("Change");
							}
							else{
								if(!tmp.contains(vertices[label])){
									tmp.add(vertices[label]);
									System.out.println("Unchange");
								}
							}
							
						}
					}
					
				}
				System.out.println("Head"+tmp.peek().label);
				Vertex candidate = tmp.remove();
					processed.add(candidate);
				distances[candidate.label] = candidate.score;
				
			}
		}
		
		return distances;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DijkstraAlgorithm a = new DijkstraAlgorithm();
		Vertex[] vertices = new Vertex[num + 1];
		vertices[0] = null;
		try {
			
			File fileinput = new File(args[0]);
			Scanner fileScanner = new Scanner(fileinput);
			int index = 1;
			while(fileScanner.hasNext()){
				String line = fileScanner.nextLine();
				String[] chars = line.split("\\s+");
				int label = 0;
				ArrayList<Integer[]> neighbor = new ArrayList<Integer[]>();
				for (int i = 0; i < chars.length; i++){
					if (i == 0){
						label = Integer.parseInt(chars[i]);
					}
					else{
						String[] tuple = chars[i].split(",");
						Integer[] tuple_num = new Integer[2];
						tuple_num[0] = Integer.parseInt(tuple[0]);
						tuple_num[1] = Integer.parseInt(tuple[1]);
						neighbor.add(tuple_num);
					}
				}
				vertices[index] = a.new Vertex(label, neighbor);
				index++;
			}
			fileScanner.close();
			System.out.println("Terminated");
		}
		catch(Exception e){
			System.err.println("ERROR");
			e.printStackTrace();
		}
		
				Integer[] result = a.HeapDijkstra(vertices, vertices[1]);
				System.out.println("Result:");
				for (int i = 1; i < result.length; i++){
					System.out.println(result[i]);
				}
				 
				System.out.println("Final: "+result[7]+","+result[37]+","+result[59]+","+result[82]+","+result[99]+","+result[115]+","
						+result[133]+","+result[165]+","+result[188]+","+result[197]);
	}

}
