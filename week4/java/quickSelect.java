import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class quickSelect {

    static Random random = new Random();

    public static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static int partition(int[] arr, int low, int high) {

        int pivot = arr[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                swap(arr, i, j);
                i++;
            }
        }

        swap(arr, i, high);

        return i;
    }

    public static void quickSelect(int[] arr, int low, int high, int k) {

        while (low <= high) {

          
            int pivotIndex = low + random.nextInt(high - low + 1);
            swap(arr, pivotIndex, high);

            int p = partition(arr, low, high);

            if (p == k)
                return;
            else if (p > k)
                high = p - 1;
            else
                low = p + 1;
        }
    }

    public static void main(String[] args) throws IOException {

        int[] sizes = {
                10000,
                20000,
                40000,
                80000,
                160000,
                320000,
                640000,
                1000000
        };

        FileWriter file = new FileWriter("quickselect_runtime.csv");

        file.write("Dataset_Size,Runtime_ms\n");

        for (int n : sizes) {

            double total = 0;

            for (int test = 0; test < 10; test++) {

                int[] arr = new int[n];

                for (int i = 0; i < n; i++) {
                    arr[i] = random.nextInt(10000000);
                }

                int k = n / 10;

                long start = System.nanoTime();

                quickSelect(arr, 0, n - 1, k - 1);

                long end = System.nanoTime();

                total += (end - start) / 1000000.0;
            }

            double avg = total / 10;

            System.out.printf("%d -> %.3f ms%n", n, avg);

            file.write(n + "," + avg + "\n");
        }

        file.close();

        System.out.println("\nquickselect_runtime.csv created successfully.");
    }
}