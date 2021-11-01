--13

select E.FIRST_NAME, E.LAST_NAME,E.SALARY
FROM employees as E, jobs as J
WHERE E.JOB_ID = J.JOB_ID 
AND E.SALARY = J.MIN_SALARY


--10
SELECT j.job_id,j.job_title,AVG(e.SALARY) AS 'TRUNG BINH LUONG'
FROM jobs AS j LEFT JOIN employees as e on j.JOB_ID = e.JOB_ID
group by j.JOB_ID


--11
SELECT FIRST_NAME, LAST_NAME,SALARY
FROM employees
WHERE SALARY > 
	(SELECT SALARY
	FROM employees 
	WHERE LAST_NAME = N'BULL')

--1
SELECT FIRST_NAME AS "first_name", LAST_NAME AS "last_name"
from employees

--3
SELECT first_name, last_name, salary
from employees
order by FIRST_NAME

--2
SELECT distinct MANAGER_ID
FROM departments

--4
SELECT SUM(SALARY)
FROM employees

--5chua ok
SELECT E.EMPLOYEE_ID,E.FIRST_NAME,E.LAST_NAME,E.SALARY
FROM employees AS E
WHERE E.SALARY IN(SELECT TOP 1 SALARY 
					FROM employees
					ORDER BY SALARY ASC)
	OR E.SALARY IN(SELECT TOP 1 SALARY
					FROM employees
					ORDER BY SALARY DES)

--6chua ok
SELECT DEPARTMENT_ID,LOCATION_ID,STREET_ADDRESS, CITY
FROM DEPARTMENT D INNER JOIN LOCATION L 
		ON D.LOCATION_ID = L.LOCATION_ID


--7
SELECT E.EMPLOYEE_ID,E.FIRST_NAME,E.LAST_NAME,D.DEPARTMENT_NAME
FROM employees as E, departments as D
where E.DEPARTMENT_ID = D.DEPARTMENT_ID
group by E.EMPLOYEE_ID, E.FIRST_NAME,E.LAST_NAME,D.DEPARTMENT_NAME


--8
SELECT E.FIRST_NAME,E.LAST_NAME,J.JOB_TITLE,E.DEPARTMENT_ID
FROM employees AS E, departments AS D, locations AS L, jobs AS J
WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID
AND E.JOB_ID = J.JOB_ID
AND D.LOCATION_ID = L.LOCATION_ID
AND L.CITY = N'HANOI' 


--9
SELECT D.DEPARTMENT_NAME
from departments  as D, employees as E
where D.DEPARTMENT_ID = E.DEPARTMENT_ID
group by D.DEPARTMENT_NAME



--Bai_KiemTra Gio ly thuyet
--1

select first_name, last_name,salary
from employees
where SALARY not between 10000 and 15000

--2
select first_name,last_name, job_title
from employees, jobs
where employees.JOB_ID = jobs.JOB_ID
	and	(job_title = 'Programmer'
		or job_title = 'designer')
		and salary > 1000


--3
select job_title,SUM(salary) as N'Tong Luong',max_salary,min_salary, AVG(salary)
from employees,jobs
where DEPARTMENT_ID = 90 and employees.JOB_ID=jobs.JOB_ID
group by job_title,MAX_SALARY,MIN_SALARY



					









