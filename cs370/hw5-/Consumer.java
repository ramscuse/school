import java.util.logging.Level;
import java.util.logging.Logger;

public class Consumer extends java.lang.Thread {
    
    Buffer buff;
    int id;
    int itemAmount;

    int Checksum;
    
    public Consumer(Buffer buff, int id, int x){
        this.buff = buff;
        this.id = id;
        itemAmount = x;
        Checksum = 0;
    }
    
    public int sum() {
        return Checksum;
    }

    @Override
    public void run() {
        synchronized(buff) {
            for(int i = 0; i < itemAmount; i++) {
                int item[];
                if (buff.isEmpty()) {
                    try {
                        buff.wait();
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Consumer.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                item = buff.read();
                Checksum += item[1];
                System.out.println("Consumer " + id + " read " + item[1] + " at index " + 
                            item[0] + " at time " + Coordinator.getTime());
               // itemAmount -= 1;
                buff.notify();
            }
        }
        // if (itemAmount > 0)
        //     run();
    }
}