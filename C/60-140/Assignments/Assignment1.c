#include <stdio.h>

int main(void)
{
	float t1wd, t1cd, t1td, t1sd, t2wd, t2cd, t2td, t2sd, t3wd, t3cd, t3td, t3sd, t1wn, t1cn, t1tn, t1sn, t2wn, t2cn, t2tn, t2sn, t3wn, t3cn, t3tn, t3sn;
	float totd1, totd2, totd3, totd123, totlbs1, totlbs2, totlbs3, totlbs123;
	float HST, wlbs, clbs, tlbs, slbs;
	
	HST = 1.13;
	wlbs = 150;
	clbs = 5;
	tlbs = 4;
	slbs = 3;
	
	printf("\n");
	printf("How many cases of bottled water in trunk 1?\t ");
	scanf("%f", &t1wn);
	printf("How much did each case in trunk 1 cost?\t\t$");
	scanf("%f", &t1wd);
	printf("How many boxes of cereal in trunk 1?\t\t ");
	scanf("%f", &t1cn);
	printf("How much did each box in trunk 1 cost?\t\t$");
	scanf("%f", &t1cd);
	printf("How many T-shirts in trunk 1?\t\t\t ");
	scanf("%f", &t1tn);
	printf("How much did each shirt in trunk 1 cost?\t$");
	scanf("%f", &t1td);
	printf("How many dozens of ivory soap in trunk 1?\t ");
	scanf("%f", &t1sn);
	printf("How much did each dozen in trunk 1 cost?\t$");
	scanf("%f", &t1sd);
	
	printf("\n");
	printf("How many cases of bottled water in trunk 2?\t ");
	scanf("%f", &t2wn);
	printf("How much did each case in trunk 2 cost?\t\t$");
	scanf("%f", &t2wd);
	printf("How many boxes of cereal in trunk 2?\t\t ");
	scanf("%f", &t2cn);
	printf("How much did each box in trunk 2 cost?\t\t$");
	scanf("%f", &t2cd);
	printf("How many T-shirts in trunk 2?\t\t\t ");
	scanf("%f", &t2tn);
	printf("How much did each shirt in trunk 2 cost?\t$");
	scanf("%f", &t2td);
	printf("How many dozens of ivory soap in trunk 2?\t ");
	scanf("%f", &t2sn);
	printf("How much did each dozen in trunk 2 cost?\t$");
	scanf("%f", &t2sd);
	
	printf("\n");
	printf("How many cases of bottled water in trunk 3?\t ");
	scanf("%f", &t3wn);
	printf("How much did each case in trunk 3 cost?\t\t$");
	scanf("%f", &t3wd);
	printf("How many boxes of cereal in trunk 3?\t\t ");
	scanf("%f", &t3cn);
	printf("How much did each box in trunk 3 cost?\t\t$");
	scanf("%f", &t3cd);
	printf("How many T-shirts in trunk 3?\t\t\t ");
	scanf("%f", &t3tn);
	printf("How much did each shirt in trunk 3 cost?\t$");
	scanf("%f", &t3td);
	printf("How many dozens of ivory soap in trunk 3?\t ");
	scanf("%f", &t3sn);
	printf("How much did each dozen in trunk 3 cost?\t$");
	scanf("%f", &t3sd);
	
	totd1 = ((t1wd*t1wn)+(t1cd*t1cn)+(t1td*t1tn)+(t1sd*t1sn))*HST;
	totd2 = ((t2wd*t2wn)+(t2cd*t2cn)+(t2td*t2tn)+(t2sd*t2sn))*HST;
	totd3 = ((t3wd*t3wn)+(t3cd*t3cn)+(t3td*t3tn)+(t3sd*t3sn))*HST;
	totd123 = totd1+totd2+totd3;
	totlbs1 = (t1wn*wlbs)+(t1cn*clbs)+(t1tn*tlbs)+(t1sn*slbs);
	totlbs2 = (t2wn*wlbs)+(t2cn*clbs)+(t2tn*tlbs)+(t2sn*slbs);
	totlbs3 = (t3wn*wlbs)+(t3cn*clbs)+(t3tn*tlbs)+(t3sn*slbs);
	totlbs123 = totlbs1+totlbs2+totlbs3;
	
	printf("\n");
	printf("Details of Goods sent by QR Charity Agency:\n");
	printf("******************************\n");
	printf("Total cost of goods in Trunk 1 with HST is: \t\t $%.2f\n", totd1);
	printf("Total cost of goods in Trunk 2 with HST is: \t\t $%.2f\n", totd2);
	printf("Total cost of goods in Trunk 3 with HST is: \t\t $%.2f\n", totd3);
	printf("******************************\n");
	printf("Total cost of goods in the three trunks with HST is: \t $%.2f\n", totd123);
	printf("******************************\n");
	printf("Total weight of goods in Trunk 1 is: \t\t\t %.0f lbs\n", totlbs1);
	printf("Total weight of goods in Trunk 2 is: \t\t\t %.0f lbs\n", totlbs2);
	printf("Total weight of goods in Trunk 3 is: \t\t\t %.0f lbs\n", totlbs3);
	printf("******************************\n");
	printf("Total weight of goods in the three trunks is: \t\t %.0f lbs\n", totlbs123);
	printf("******************************\n");
	
	return 0;
}
