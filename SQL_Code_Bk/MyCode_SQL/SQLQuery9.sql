select FirstName,LastName,Age
from Customer
where FirstName='Mark'
and LastName like 'Yellow_';

update Customer
set Age=35
where FirstName='Mark'
and LastName like 'Yellow_';

