#pragma once

#define SINGLETON(ClassType)		public:\
										 static CEngine* GetInst()\
										{\
											static CEngine engine;\
											return &engine;\
										}\
										public:\
											ClassType* operator = (const ClassType& _Origin) = delete;\
										private:\
											ClassType();\
											ClassType(const ClassType& _Origin) = delete;\
											~ClassType();

