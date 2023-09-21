#pragma once
class TaskMgr
{
	SINGLETON(TaskMgr);

private:
	vector<FTask> mVecTask;

public:
	void tick();

	void addTask(const FTask& _task) {
		mVecTask.push_back(_task);
	}

};

