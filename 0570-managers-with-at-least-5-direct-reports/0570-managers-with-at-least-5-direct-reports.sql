select emp1.name as name
from employee emp1 join employee emp2 on emp1.id = emp2.managerId
group by emp1.id
having count(emp2.id) >= 5;