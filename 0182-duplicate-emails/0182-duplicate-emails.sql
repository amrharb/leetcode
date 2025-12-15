select distinct P1.email as Email
from Person P1 join Person P2 on P1.email = P2.email and P1.id <> P2.id;