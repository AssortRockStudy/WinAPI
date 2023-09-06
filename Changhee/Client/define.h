#pragma once

#define SINGLETON(ClassType)		public:\
										 static ClassType* GetInst()\
										{\
											static ClassType mgr;\
											return &mgr;\
										}\
										public:\
											ClassType* operator = (const ClassType& _Origin) = delete;\
										private:\
											ClassType();\
											ClassType(const ClassType& _Origin) = delete;\
											~ClassType();

