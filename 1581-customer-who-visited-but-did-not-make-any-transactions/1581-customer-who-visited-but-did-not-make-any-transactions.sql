select customer_id, count(*) as count_no_trans
from visits v1
where not exists (select visit_id from Transactions where visit_id = v1.visit_id)
group by customer_id;