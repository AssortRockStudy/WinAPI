#pragma once
class TaskMgr
{
	SINGLETON(TaskMgr);

private: 
	vector<FTask> m_vecTask;

public:
	void tick();
	void AddTask(const FTask& _Task)
	{
		m_vecTask.push_back(_Task);
	}
};

