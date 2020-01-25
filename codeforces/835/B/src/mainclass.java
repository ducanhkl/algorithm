import java.util.*;
public class 835B

{
	public static void main(String[] args)
	{
	  try(Scanner sc = new Scanner(System.in))
	  {
	  int[] cnt = new int[10];
	  int k = sc.nextInt();
	  String n = sc.next();
	  int cur = 0;
	  for(int i = 0; i < n.length(); i++) {
		  int digit = n.charAt(i) - '0';
		  cnt[digit]++;
		  cur += digit;
	  }
	  int ans = 0;
	  for(int i = 0; i < 9; i++){
		  for(int j = 0; j < cnt[i]; j++){
			  if(cur < k){
				  ans++;
				  cur += 9 - i;
			  }
		  }
	  }
	  System.out.println(ans);
	  }
	}
}