UPDATE employees SET salary=7000 WHERE last_name= 'Bell';

ROLLBACK;

--접속 B의 Serializable에서 lock을 걸지 않아 접속 A가 같은 값에 대하여 접근을 하기 때문이다. 
--이는 다중버전 동시성 제어(MVCC)을 통하여 동시성과 일관성을 높여 해결할 수 있다.