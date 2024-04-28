select
    u.unique_id,
    e.name
from
    EmployeeUNI as u
right join
    Employees as e
ON
    u.id=e.id