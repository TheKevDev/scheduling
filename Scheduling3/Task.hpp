/*
 * Task.hpp
 *
 *  Created on: 22 sep. 2017
 *      Author: Stefan
 */

#ifndef TASK_HPP_
#define TASK_HPP_

class Task
{
public:
	Task(long id, long jobId, long machine, long duration);
	Task();
	virtual ~Task();

	long getDuration() const
	{
		return duration;
	}

	void setDuration(long duration)
	{
		this->duration = duration;
	}

	long getId() const
	{
		return id;
	}

	long getMachine() const
	{
		return machine;
	}

	long getJobId() const
	{
		return jobId;
	}


private:
	long id;
	long jobId;
	long machine;
	long duration;
};

#endif /* TASK_HPP_ */
