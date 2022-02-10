class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int steps = 0;
        
        
        int remCap = capacity;
        
        int s = -1;
        while(s<=(plants.length-2)){
            if(plants[s+1]<=remCap){
                remCap = remCap - plants[s+1];
                s++;
                steps++;
                
            }
            else{
                remCap = capacity;
                steps = steps + (s+1)*2;
                
            }
            
            
        }
        
        return steps;
        
    }
}
