-- 동물 보호소에 들어온 동물의 정보를 담은 테이블
-- 동물의 생물 종, 이름, 성별 및 중성화 여부를 아이디 순으로 조회하는 SQL문을 작성
-- 이름이 없는 동물의 이름은 "No name"으로 표시

SELECT ANIMAL_TYPE,	IFNULL(NAME, 'No name'), SEX_UPON_INTAKE
FROM ANIMAL_INS
ORDER BY ANIMAL_ID;