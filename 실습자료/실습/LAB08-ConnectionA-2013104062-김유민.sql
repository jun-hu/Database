UPDATE employees SET salary=7000 WHERE last_name= 'Bell';

ROLLBACK;

--���� B�� Serializable���� lock�� ���� �ʾ� ���� A�� ���� ���� ���Ͽ� ������ �ϱ� �����̴�. 
--�̴� ���߹��� ���ü� ����(MVCC)�� ���Ͽ� ���ü��� �ϰ����� ���� �ذ��� �� �ִ�.