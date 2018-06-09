UPDATE employees SET salary=7000 WHERE last_name= 'Bell';
ROLLBACK;

--갱신하려는 데이터에 대해서는 독점 로크를 걸고 트랜잭션이 끝날때까지 보유해서  update나 insert는 할수 없기 때문에