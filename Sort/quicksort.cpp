#include <sstream>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
//NB: need start and end to determine where to divide each level's lower and
//	upper sublist; params: start, end refer to indices of cur list
	void quickSort(int *list, int start, int end)//initially:start=0, end=size-1
	{
		//STEP 1 - get pivot and initalize smallIndex to point to first itm where
		//	pivot is temporarily placed to sort rest of list(smallIndex pts to end
		//	of lower sublist(=> elems < pivot)
		int pivot = (start + end)/2;
		int smallIndex = start;//lower sublist holds items >= pivot but
		//	initially smallIndex initialized to first item (which is where pivot
		//	elem temporarily stored (moved out of the way to sort rest of sublist)

		/**DIVIDE STAGE**/
		if ( start < end )//if more than one elem, then partition
		{
			//STEP 2 - mov pivot to first index and iterate to sort cur sublist
			int tempA = list[start];
			list[start] = list[pivot];
			list[pivot] = tempA;

			//iterate cur sublist and mov items to lower or upper sublist
			for ( int i = start + 1; i <= end; i++ )//DON'T compare pivot, start @ indx one over
			{
				//"add" to lower sublist
				if ( list[i] <= list[start] )//NB: we temporarily moved pivot elm to list front
				{
					smallIndex+=1;
					int tempB = list[i];
					list[i] = list[smallIndex];
					list[smallIndex] = tempB;
				}
			}
			//STEP 3 - mov pivot to where it belongs (=> swap positions w. end of
			//	cur sublist (so the indx smallIndex is boundary b/t lower and upper
			//	sublist
			//Once you reach end of list, time to move pivot where it belongs
			//	=> trade places with index smallIndex
			int tempC = list[start];//pivot elem is here, need to move to where
			//	indx smallIndx is
			list[start] = list[smallIndex];
			list[smallIndex] = tempC;

			//STEP 4 - update the pivot index to use for dividing potential
			//	next level's lower and upper sublists
			pivot = smallIndex;

			quickSort(list,start,pivot - 1);//partition lower sublist
			quickSort(list,pivot + 1,end);//partition upper sublist

			/**COMBINE STAGE, trivial array all sorted in place, no extra
			array needed!**/
		}//END BIG IF
	}//END quickSort

int main()
{
	//read data into array and sort
	ifstream ifs;
	ifs.open("reversedData1000000.txt");/*CHANGE TO OPEN APPROPRIATE DATA FILE*/
	int arraySize = 1000000;/*CHANGE TO APPROPRIATE SIZE*/
	int *list = new int[arraySize];

	for ( int i = 0; i < arraySize; i++ )
	{
		ifs >> list[i];//read from a file into each index in array
	}

	clock_t startTime = clock();
	quickSort(list, 0, arraySize - 1);
	clock_t endTime = clock();
	clock_t duration = double(endTime - startTime);

	string quickSortedList = printList(list,arraySize);

	ifs.close();

	//store sorted list to new file
	ofstream ofs;
	ofs.open("reversedData1000000QuickSorted_3.txt");/*CHANGE TO APPROPRIATE SORTED FILE NAME TO SAVE RESULTS TO*/

	ofs <<"Sort time: "<<duration<<" ms"<<endl<<endl<< quickSortedList;
	ofs.close();

	cout<<"Sort time:"<<duration<<" ms"<<endl;

	return 0;
}
