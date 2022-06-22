-- 정확히 이렇게 제출하지 않았을 수 있음.

SELECT first_name, last_name, room_no
FROM customers
JOIN reservations
ON customers.customer_id = reservations.customer_id
WHERE ("2022-01-01" <= date_in AND date_in <= "2022-01-30") OR ("2022-01-02" <= date_out AND date_out <= "2022-01-31")
ORDER BY first_name, last_name, room_no
