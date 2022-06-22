import java.lang.Exception;
import java.util.Random;
import java.time.Instant;
import java.time.Clock;
import java.time.Duration;
import java.util.logging.Level;
import java.util.logging.Logger;

class Coordinator { // Should be Coordinator
	public static void main(String[] args) {
		if (args.length != 5) {
			System.out.print("Not the right amount of arguements!\n");
			System.exit(1);
		}
		int bufferSize = Integer.parseUnsignedInt(args[0]);
		int items = Integer.parseUnsignedInt(args[1]);
		int consumerAmount = Integer.parseUnsignedInt(args[2]);
		int producerAmount = Integer.parseUnsignedInt(args[3]);
		int seed = Integer.parseUnsignedInt(args[4]);
                
		System.out.println(bufferSize + " " + items + " " + consumerAmount + " "
							+ producerAmount + " " + seed);
		
		Buffer buff = new Buffer(bufferSize);
		
		Producer producers[] = new Producer[producerAmount];
		Consumer consumers[] = new Consumer[consumerAmount];
        
		int itemsforProducer = items/producerAmount;
		int extraitemsProducer = items%producerAmount;
		int itemsforConsumer = items/consumerAmount;
		int extraitemsConsumer = items%consumerAmount;

		for (int i = 0; i < producerAmount; i++) {
			if (extraitemsProducer > 0) {
				producers[i] = new Producer(buff, itemsforProducer + 1, i + 1, seed);
				extraitemsProducer -= 1;
			} else {
				producers[i] = new Producer(buff, itemsforProducer, i + 1, seed);
			}
		}
		for (int i = 0; i < consumerAmount; i++) {
			if (extraitemsConsumer > 0) {
				consumers[i] = new Consumer(buff, i + 1, itemsforConsumer + 1);
				extraitemsConsumer -= 1;
			} else {
				consumers[i] = new Consumer(buff, i + 1, itemsforConsumer);
			}
		}
		System.out.println("");
		
			
		for (int i = 0; i < producerAmount; i++) {
			producers[i].start();
		}
		for (int i = 0; i < consumerAmount; i++) {
			consumers[i].start();
		}

		for (int i = 0; i < producerAmount; i++) {
			try {
				producers[i].join();
			} catch (InterruptedException ex) {
				Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
			}
		}
		for (int i = 0; i < consumerAmount; i++) {
			try {
				consumers[i].join();
			} catch (InterruptedException ex) {
				Logger.getLogger(Producer.class.getName()).log(Level.SEVERE, null, ex);
			}
		}

		int prosum = 0;
		int consum = 0;
		for (int i = 0; i < producerAmount; i++) {
			prosum += producers[i].sum();
		}
		for (int i = 0; i < consumerAmount; i++) {
			consum += consumers[i].sum();
		}

		System.out.println();
		System.out.println("Producer(s): Finished producing " + items + 
			" with checksum being " + prosum);
		System.out.println("Consumer(s): Finished consuming " + items +
			" with checksum being " + consum);
	}

	//Call this function from your producer or your consumer to get the time stamp to be displayed
	public static String getTime() {
		Clock offsetClock = Clock.offset(Clock.systemUTC(), Duration.ofHours(-9));
		Instant time = Instant.now(offsetClock);
		String timeString = time.toString();
		timeString = timeString.replace('T', ' ');
		timeString = timeString.replace('Z', ' ');
		return(timeString);
	}
}