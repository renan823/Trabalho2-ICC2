bubble:
	gcc bubble.c -std=c99 -Wall -o bubble
	
selection:
	gcc selection.c -std=c99 -Wall -o selection

insertion:
	gcc insertion.c -std=c99 -Wall -o insertion

quick:
	gcc quick.c -std=c99 -Wall -o quick

heap:
	gcc heap.c -std=c99 -Wall -o heap

clear:
	rm bubble selection insertion quick heap 