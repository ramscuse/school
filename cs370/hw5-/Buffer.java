public class Buffer {

    int[] list;
    int indexI;
    int indexR;
    int maxSize;

    public Buffer(int maxSize){
        this.maxSize = maxSize;
        list = new int[maxSize];
        for (int i = 0; i < list.length; i++) {
            list[i] = -1;
        }
        indexR = 0;
        indexI = 0;
    }
    
    public int[] read() {
        int temp[] = new int[2];
        temp[0] = indexR;
        temp[1] = list[indexR];
        list[indexR] = -1;
        indexR +=1;
        if (indexR == maxSize)
            indexR = 0;
        return temp;
    }
    
    public int insert(int item) {
        int temp = indexI;
        list[indexI] = item;
        indexI += 1;
        if (indexI == maxSize)
            indexI = 0;
        return temp;
    }
    
    public boolean isFull() {
        for (int i = 0; i < list.length; i++) {
            if (list[i] == -1)
                return false;
        }
        return true;
    }
    
    public boolean isEmpty() {
        for (int i = 0; i < list.length; i++) {
            if (list[i] != -1)
                return false;
        }
        return true;
    }
}