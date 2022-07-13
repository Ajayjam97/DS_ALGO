#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
  
using namespace std;

// public class HashMap{

//     private class HMNode{
//         string key;
//         int value;

//         HMNode(K key, V value) {
//         this.key = key;
//         this.value = value;
//       }
//     }

//     private int size; // n
//     private vector<vector<HMNode>> buckets; // N = buckets.length

    
//     public HashMap() {
//       initbuckets(4);
//       size = 0;
//     }

//     private void initbuckets(int N) {
//       buckets = new vector(N);
//       for (int bi = 0; bi < buckets.length; bi++) {
//         buckets[bi] = new vector<HMNode>();
//       }
//     }

//     public void put(string key, int value) {
//       // write your code here
//     }

//     public int get(string key) {
//       // write your code here
//     }

//     public boolean containsKey(string key) {
//       // write your code here
//     }

//     public int remove(string key) {
//       // write your code here
//     }

//     public vector<string> keyset() {
//       // write your code here
//     }

//     public int size() {
//       // write your code here
//     }

// }

int main(){

    unordered_map<string, int> mymap;

    //insert
    pair<string, int> p("abc", 1);
    mymap.insert(p);

    mymap["def"] = 2; //like array

    //find or access
    cout<<mymap["abc"]<<endl;
    cout<<mymap.at("abc")<<endl;

    //check presence of a key
    if(mymap.count("ghi")!=0) cout<<mymap.at("ghi")<<endl;

    if(mymap.count("def")!=0) cout<<mymap.at("def")<<endl;

    return 0;
}



//    public void display() {
//       System.out.println("Display Begins");
//       for (int bi = 0; bi < buckets.length; bi++) {
//         System.out.print("Bucket" + bi + " ");
//         for (HMNode node : buckets[bi]) {
//           System.out.print( node.key + "@" + node.value + " ");
//         }
//         System.out.println(".");
//       }
//       System.out.println("Display Ends");
//   }
// }

//   public static void main(String[] args) throws Exception {
//     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
//     HashMap<String, Integer> map = new HashMap();

//     String str = br.readLine();
//     while (str.equals("quit") == false) {
//       if (str.startsWith("put")) {
//         String[] parts = str.split(" ");
//         String key = parts[1];
//         Integer val = Integer.parseInt(parts[2]);
//         map.put(key, val);
//       } else if (str.startsWith("get")) {
//         String[] parts = str.split(" ");
//         String key = parts[1];
//         System.out.println(map.get(key));
//       } else if (str.startsWith("containsKey")) {
//         String[] parts = str.split(" ");
//         String key = parts[1];
//         System.out.println(map.containsKey(key));
//       } else if (str.startsWith("remove")) {
//         String[] parts = str.split(" ");
//         String key = parts[1];
//         System.out.println(map.remove(key));
//       } else if (str.startsWith("size")) {
//         System.out.println(map.size());
//       } else if (str.startsWith("keyset")) {
//         System.out.println(map.keyset());
//       } else if (str.startsWith("display")) {
//         map.display();
//       }
//       str = br.readLine();
//     }
//   }