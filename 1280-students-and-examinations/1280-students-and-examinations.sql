select st.student_id as student_id, student_name, sub.subject_name  as subject_name , count(exam.student_id) as attended_exams 
from subjects sub cross join students st
                  left join examinations exam on exam.student_id = st.student_id and exam.subject_name = sub.subject_name
group by st.student_id, st.student_name, sub.subject_name
order by st.student_id, sub.subject_name;