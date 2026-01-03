public class TrailingZero {

   
    public static int countTrailingZeroes(int x) {
        int count = 0;
        for (int i = 5; x / i >= 1; i *= 5) {
            count += x / i;
        }
        return count;
    }


    public static int findNumber(int n) {
        int low = 0;
        int high = 5 * n;  
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int zeros = countTrailingZeroes(mid);

            if (zeros >= n) {
                ans = mid;
                high = mid - 1; 
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int n1 = 1;
        int n2 = 6;

        System.out.println("Input: n = " + n1 + " → Output: " + findNumber(n1));  
        System.out.println("Input: n = " + n2 + " → Output: " + findNumber(n2)); 
    }
}
