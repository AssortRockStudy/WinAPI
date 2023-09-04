#pragma once
					#define SINGLETON(ClassType)		public:\
												static CEngine* GetInst()\
												{\
													static CEngine engine;\
													return &engine;\
												}\
											public:\
														ClassType& operator = (const ClassType& _Origin) = delete;\
													private:\
														CEngine();\
											public:\
											static CEngine* pEngine;\
													~CEngine();\

