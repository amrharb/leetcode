select author_id as id
from views v1
group by id
having id in (select viewer_id from views where author_id = id)
order by id;