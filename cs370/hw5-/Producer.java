import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Producer extends java.lang.Thread {
    //Necessary variables and object declaration
    Random randomWithSeed;
    Buffer buff;
    int itemAmount;
    int id;
    
    int Checksum;


    public Producer(Buffer buff, int count, int id, int seed) {
        //Assign values to the variables
        randomWithSeed = new Random(seed);
        this.buff = buff;
        itemAmount = count;
        this.id = id;
        Checksum = 0;
    }

    public int sum() {
        return Checksum;
    }

    @Override
    public void run() {
//		---> To generate a value between 0 (inclusive) and 99 (inclusive) using the seeded random  
//                ---> number generator use the following code :
//                --->       int variable = randomWithSeed.nextInt(100);
        synchronized(buff) {
            for (int i = 0; i < itemAmount; i++) {
                int item = randomWithSeed.nextInt(100);
                if (buff.isFull()) {
                    try {
                        buff.wait();
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                int loc = buff.insert(item);
                Checksum += item;
                if ( loc >=0) {
                    System.out.println("Producer " + id + " inserted " + item + " at index " + 
                            loc + " at time " + Coordinator.getTime());
                    // itemAmount -= 1;
                    buff.notify();
                } else {
                    System.out.println("Error occured when inserting");
                    System.exit(-1);
                }
            }
        }
        // if (itemAmount > 0)
        //     run();
    }
}