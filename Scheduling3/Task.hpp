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
	virtual ~Task();
	void setStartTime(long startTime);
	void setEndTime(long endTime);
	void setPlanned(bool planned);

	long getEs() const
	{
		return ES;
	}

	void setEs(long es)
	{
		ES = es;
	}

	long getLs() const
	{
		return LS;
	}

	void setLs(long ls)
	{
		LS = ls;
	}

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

	long getEndTime() const
	{
		return endTime;
	}

	long duration;

private:
	long id;
	long jobId;
	long machine;
	long startTime;
	long endTime;
	bool planned;
	long ES;
	long LS;
};

#endif /* TASK_HPP_ */
