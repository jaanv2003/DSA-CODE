/* Appending two linked list based upon two data members
of individual linked list objects. */

class CClass1
{
public:
	char mStringData[10];;

	long int mDataMember1;
	long int mDataMember2;
	CClass1 *structpNextValue;

	void SetValue(CString string, long int a, long int b)
	{
		strcpy(mStringData, string);
		mDataMember1 = a;
		mDataMember2 = b;
	}
	CClass1(void);
	~CClass1(void);
};
///////////////////////////////////////////////////////////////////////
class CClass2
{
public:

	char mStringData[10];
	long int mDataMember1;
	long int mDataMember2;

	CClass2 *structpNextValue;

	void SetValue(CString string, long int a, long int b)
	{
		strcpy(mStringData, string);
		mDataMember1 = a;
		mDataMember2 = b;
	}

	CClass2(void);
	~CClass2(void);
};
///////////////////////////////////////////////////////////////////////

                CClass1	*pstrTemp;

		lTemp = lNumOrphanRecord;

		pstrTemp = (CClass1*)malloc(sizeof(CClass1));
		pstrTemp->structpNextValue = NULL;

 		CClass2 *pstrExcTemp = &mObject2[0];

		while(lTemp > 0)
		{
			pstrTemp->mDataMember1	    = pstrExcTemp->mDataMember1;
			strcpy(pstrTemp->mStringData, pstrExcTemp->mStringData);
			pstrTemp->mDataMember2		= pstrExcTemp->mDataMember2;

			pstrExcTemp = pstrExcTemp->structpNextValue;


			if (mObject1->mDataMember1 == 0)
			{
				mObject1 = pstrTemp;
			}
			else
			{
				CClass1	*pstrPrev = NULL;
				CClass1	*pstrCurr = mObject1;
				long int tempSeqNum = mObject1->mDataMember1;
				int Icount=0;

				while ( (pstrCurr) &&(pstrCurr->mDataMember1 !=0) &&
(pstrCurr->mDataMember1 < pstrTemp->mDataMember1) )
				{
 					pstrPrev = pstrCurr;
					pstrCurr = pstrCurr->structpNextValue;
				}

				if ((pstrCurr) && (pstrCurr->mDataMember1 == 
pstrTemp->mDataMember1) )
				{
					if (pstrCurr->mDataMember2 < pstrTemp->mDataMember2)
					{
						pstrTemp->structpNextValue = pstrCurr->structpNextValue;
						free(pstrCurr);
						pstrCurr = pstrTemp;

						if (tempSeqNum == pstrTemp->mDataMember1)
						{
							mObject1 = pstrCurr;
						}
						if(pstrPrev)
						{
							pstrPrev->structpNextValue = pstrCurr;
						}
					}
					if(!pstrTemp)
						pstrTemp = NULL;

					lNumOrphanRecord--;

				}
			else
			{
				if (pstrPrev)
				{
					pstrPrev->structpNextValue = pstrTemp;
					pstrTemp->structpNextValue = pstrCurr;
				}
				else
				{
					pstrTemp->structpNextValue = pstrCurr;
					mObject1 = pstrTemp;
				}
			}
			}
			pstrTemp = (CClass1*)malloc(sizeof(CClass1));
			pstrTemp->structpNextValue = NULL;
			lTemp--;
		}

		lNumRecord += lNumOrphanRecord;
		pstrExcTemp = &mObject2[0];
		pstrExcTemp = pstrExcTemp->structpNextValue;

		while(mObject2->structpNextValue != NULL)
		{
			pstrExcTemp = mObject2->structpNextValue;
			mObject2->structpNextValue = pstrExcTemp->structpNextValue;
		        if(!pstrExcTemp)
			  pstrExcTemp = NULL;
		}
