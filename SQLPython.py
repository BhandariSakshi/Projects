import pymysql 

conn = pymysql.connect(
    host = 'localhost',
    user = 'root',
    password = 'Sakshi@234',
    database = 'pywit'
)

cur = conn.cursor()

"""  
Class Name : DDL
Description : Data Definition Language is used for defining, altering, and deleting database structures such as tables, indexes, and schemas.

"""

class DDL:
    """
    Method Name : createTable
    Description : Used for creating new table with required columns
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def createTable(self):
        """Creates a table with user input for the table name and columns"""
        try:
            tname = input("Enter the table name you want to create: ")
            
            num_columns = int(input("How many columns do you want to create? "))
            
            columns = []
            
            for i in range(num_columns):
                col_name = input(f"Enter name for column {i+1}: ")  
                col_type = input(f"Enter data type for column {i+1} (e.g., INT, VARCHAR(50), DATE, etc.): ")  
                columns.append(f"{col_name} {col_type}")  
            
            columns_str = ", ".join(columns)
            
            query = f"CREATE TABLE {tname} ({columns_str})"
            
            cur.execute(query)
            print(f"{tname} table created successfully with {num_columns} columns.")
        
        except Exception as e:
            print(f"Error creating table {tname}: {e}. Please check your input and try again.")


    """
    Method Name : TableDrop
    Description : Used for deleting the whole table from database
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def TableDrop(self,tname):
        """Drops the table"""
        try:
            query = f'drop table {tname}'
            cur.execute(query)
            print(f"{tname} deleted successfully..")
        except Exception as e: 
            print("Kindly check the syntax and table name")
    

    """
    Method Name : Truncate
    Description : Used for truncating table i.e only deleting the records from table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def Truncate(self,tname):
        """Truncates the table"""
        try:
            query = f'truncate table {tname}'
            cur.execute(query)
            print(f"{tname} Truncate Successfully..")
        except Exception as e: 
            print("Something went wrong")
    

    """
    Method Name : AddColumn
    Description : Adding a new column in existing column
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def AddColumn(self,tname,cname):
        """Adds new column into table"""
        try:
            query = f'alter table {tname} add column {cname}'
            cur.execute(query)
            print(f'new column {cname} successfully added')
        except Exception as e: 
            print("This column already exist..")
    

    """
    Method Name : Rename
    Description : Renaming the existing table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
        
    def Rename(self,oldname,newname):
        """Renames the table"""
        try:
            query = f'''alter table {oldname} rename to {newname}'''
            cur.execute(query)
            print(f"You have sucessfully renamed the table from {oldname} to {newname}")
        except Exception as e: 
            print("Kindly check table name..")
    

    """
    Method Name : ColumnRename
    Description : Used for renaming the existing column in table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def ColumnRename(self,tname,coldname,cnewname):
        """Renames the column"""
        try:
            query = f'alter table {tname} change {coldname} {cnewname}'
            cur.execute(query)
            print(f"Column {coldname} renamed to {cnewname} successfully")
        except Exception as e: 
            print("Column does not exist...")
    

    """
    Method Name : ModifyColumn
    Description : Used for modifying the datatype of the column in the table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
        
    def ModifyColumn(self,tname,column,dtype):
        """Modifies column name or column constraints"""
        try:
            query = f'alter table {tname} modify column {column} {dtype}'
            cur.execute(query)
            print('Column modified successfully...')
        except Exception as e: 
            print("This column does not exist...")
    
        
"""  
Class Name : DML
Description : The manipulation of data present in the database belong to DML or Data Manipulation Language

"""

class DML: 

    """
    Method Name : DataInsert
    Description : Used for inserting the records in the table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """       

    def DataInsert(self, tname, data):
        """Inserts records as per user's need"""
        try:
            query = f'INSERT INTO {tname} (id, name, age, location) VALUES (%s, %s, %s, %s)'

            if not data:
                data = []
                number_of_records = int(input("How many records do you want to insert? "))

                for _ in range(number_of_records):
                    while True:
                        try:
                            id = input("Enter ID (unique): ")
                            name = input("Enter Name: ")

                            age = int(input("Enter Age: "))
                            
                            city = input("Enter location: ")

                            data.append((id, name, age, city))
                            break  
                        except ValueError:
                            print("Invalid input! Age must be an integer. Please try again.")

            if not all(len(record) == 4 for record in data):
                raise ValueError("Each record must have exactly 4 values: (id, name, age, location)")

            cur.executemany(query, data)
            conn.commit()
            print("Data Inserted successfully.")

        except Exception as e:
            print(f"Error in data insertion: {e}")


    """
    Method Name : InsertManyCol
    Description : Used for inserting the columns as per users need
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
        
    def InsertManyCol(self,a):
        """Inserts columns as per users need"""
        try:
            tname = input("Set table name: ")
            while True:
                column = input('Set column name, data type and constraints or "break" : ')
                if column == 'break':
                    break
                a.append(column)
            a1 = ",".join(a)
            print(a1)
            query = f'create table {tname}({a1})'
            cur.execute(query)
            print("Run successfully...")
        except Exception as e:
            print("Error in inserting many columns..")
    

    """
    Method Name : Update
    Description : Update existing data within a table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def Update(self,tname,id):
        """Updates the data and set it to the particular value"""
        try:
            col = input("Enter the column name: ")
            value = input("Enter the value you want to update the record by: ")

            query = f"SELECT * FROM {tname} WHERE {col} = %s"
            cur.execute(query, (value,))
            a = cur.fetchone()

            if a:  
                name = input("Enter the new name: ")
                howold = input("Enter the new age: ")
                location = input("Enter the new location: ")
                city = input("Enter the new city: ")

                update_query = f'UPDATE {tname} SET name=%s, howold=%s, location=%s, city=%s WHERE id=%s'
                cur.execute(update_query, (name, howold, location, city,id))
                conn.commit()
                print("Data updated successfully.")
            else:
                print("No record found with the given criteria.")

        except Exception as e:
            print(f"Error in data updation: {e}")

    
    """
    Method Name : DeleteData
    Description : Used for the record
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
        
    def DeleteData(self,tname):
        """Deletes data using particular integer value using where clause"""
        try:
            col = input("Enter the column name: ")
            value = int(input("Enter the id of which you want to delete the record: "))
            query = f'delete from {tname} where {col} = %s'
            cur.execute(query,(value,))
            conn.commit()
            print("Data deleted successfully..")
        except Exception as e:
            print("Error in data Deletion")

    """
    Method Name : deleteByName
    Description : Used for deleting records from particular column by name
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def deleteByName(self, tname):
        """Deletes the data using a particular name with the WHERE clause"""
        try:
            
            col = input("Enter the column name: ") 
            name = input("Enter the name of which you want to delete the record: ")  

            query = f'DELETE FROM {tname} WHERE {col} = %s'

            cur.execute(query, (name,))
            conn.commit()  
            print("Data deleted successfully..")
        except Exception as e:
            print(f"Error in data Deletion: {e}")

    
    """
    Method Name : Filter
    Description : Used for filtering the data from a table by names
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def Filter(self,tname,start,end):
        """Do Filteration using like keyword"""
        try:
            query = f'select * from {tname} where name like "{start}%{end}"'
            cur.execute(query)
            a = cur.fetchall()
            print(a)
            
        except Exception as e:
            print("Error in Filter function..")
    
"""  
Class Name : DQL
Description : Data Query Language is used to get the data out of the database to perform operations with it. 

"""         

class DQL:

    """
    Method Name : SelectAll
    Description : Selects all the records from the table
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def SelectAll(tname):
        """Selects all records from a table."""
        try:
            query = f"SELECT * FROM {tname}"
            cur.execute(query)
            results = cur.fetchall()
            for row in results:
                print(row)
        except Exception as e:
            print("Error in fetching data")

    """
    Method Name : SelectWhere
    Description : Selects record with where condition
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def SelectWhere(tname, column, value):
        """Selects records based on a WHERE condition."""
        try:
            query = f"SELECT * FROM {tname} WHERE {column} = %s"
            cur.execute(query, (value,))
            results = cur.fetchall()
            for row in results:
                print(row)
        except Exception as e:
            print("Error in fetching data with condition")

    
    """
    Method Name : SelectWithLimit
    Description : Selects records with a given users limit
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def SelectWithLimit(tname, limit):
        """Selects a limited number of records."""
        try:
            query = f"SELECT * FROM {tname} LIMIT %s"
            cur.execute(query, (limit,))
            results = cur.fetchall()
            for row in results:
                print(row)
        except Exception as e:
            print("Error in fetching limited data")


    """
    Method Name : SelectSorted
    Description : Selects records in ascending or decending order
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def SelectSorted(tname, column, order="ASC"):
        """Selects all records sorted by a column (ASC/DESC)."""
        try:
            query = f"SELECT * FROM {tname} ORDER BY {column} {order}"
            cur.execute(query)
            results = cur.fetchall()
            for row in results:
                print(row)
        except Exception as e:
            print("Error in fetching sorted data")

    """
    Method Name : SelectLike
    Description : Selects record with like word
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def SelectLike(tname, column, pattern):
        """Selects records matching a pattern using LIKE."""
        try:
            query = f"SELECT * FROM {tname} WHERE {column} LIKE %s"
            cur.execute(query, (pattern,))
            results = cur.fetchall()
            for row in results:
                print(row)
        except Exception as e:
            print("Error in fetching data with LIKE pattern")

    """
    Method Name : SelectBetween
    Description : Selects record between the given range
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def SelectBetween(tname, column, start, end):
        """Selects records within a range using BETWEEN."""
        try:
            query = f"SELECT * FROM {tname} WHERE {column} BETWEEN %s AND %s"
            cur.execute(query, (start, end))
            results = cur.fetchall()
            for row in results:
                print(row)
        except Exception as e:
            print("Error in fetching data with BETWEEN condition")


"""  
Class Name : DCL
Description : Data Control Language is used to control access to data in the database by granting or revoking permissions. 

""" 

class DCL:

    """
    Method Name : GrantPrivileges
    Description : Assigns new privileges to a user account, allowing access to specific database objects, actions, or functions
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def GrantPrivileges(self,user, privileges, tname):
        """Grants specific privileges to a user on a table."""
        try:
            query = f"GRANT {privileges} ON {tname} TO '{user}'@'localhost'"
            cur.execute(query)
            conn.commit()
            print(f"Granted {privileges} on {tname} to {user}")
        except Exception as e:
            print("Error in granting privileges")

    """
    Method Name : RevokePrivileges
    Description : Removes previously granted privileges from a user account, taking away their access to certain database objects or actions.
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def RevokePrivileges(self,user, privileges, tname):
        """Revokes specific privileges from a user on a table."""
        try:
            query = f"REVOKE {privileges} ON {tname} FROM '{user}'@'localhost'"
            cur.execute(query)
            conn.commit()
            print(f"Revoked {privileges} on {tname} from {user}")
        except Exception as e:
            print("Error in revoking privileges")


"""  
Class Name : TCL
Description : Transaction Control Lanagauge is used for data saving.

"""

class TCL:

    """
    Method Name : Commit
    Description : Saves all changes made during the transaction
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def Commit():
        """Commits the current transaction, saving all changes."""
        try:
            conn.commit()
            print("Transaction committed successfully")
        except Exception as e:
            print("Error in committing transaction")

    """
    Method Name : RollBack
    Description : Undoes all changes made during the transaction
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def Rollback():
        """Rolls back the current transaction, undoing all changes."""
        try:
            conn.rollback()
            print("Transaction rolled back successfully")
        except Exception as e:
            print("Error in rolling back transaction")


    """
    Method Name : Savepoint
    Description : Creates a savepoint within the current transaction
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    def Savepoint(sp_name):
        """Creates a savepoint within the transaction."""
        try:
            query = f"SAVEPOINT {sp_name}"
            cur.execute(query)
            print(f"Savepoint {sp_name} created successfully")
        except Exception as e:
            print("Error in creating savepoint")


    """
    Method Name : RollbackToSavepoint
    Description : undoes a savepoint within the current transaction
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """
    
    def RollbackToSavepoint(sp_name):
        """Rolls back to a specific savepoint."""
        try:
            query = f"ROLLBACK TO SAVEPOINT {sp_name}"
            cur.execute(query)
            print(f"Rolled back to savepoint {sp_name}")
        except Exception as e:
            print("Error in rolling back to savepoint")

    
    """
    Method Name : ReleaseSavepoint
    Description : Deletes a savepoint within the current transaction
    Author : Sakshi Bhandari
    Data : 11/02/2025
    
    """

    def ReleaseSavepoint(sp_name):
        """Releases a savepoint, removing it from the transaction."""
        try:
            query = f"RELEASE SAVEPOINT {sp_name}"
            cur.execute(query)
            print(f"Savepoint {sp_name} released successfully")
        except Exception as e:
            print("Error in releasing savepoint")


def main():

    obj1 = DDL()

    name = input("Enter a table name which you want to create: ")
    obj1.createTable()

    name1 = input("Enter a table name which you want to drop: ")
    obj1.TableDrop(name1)

    name2 = input("Enter a table name that table you want to truncate: ")
    obj1.Truncate(name2)

    name3 = input("Enter the table name in which you want to add column: ")
    col = input("Enter the column name and its constraints: ")
    obj1.AddColumn(name3,col)

    old = input("Enter the table name which you want to rename: ")
    new = input("Enter the new name for table: ")
    obj1.Rename(old,new)

    name4 = input("Enter the table name of which you want to rename column: ")
    old = input("Enter old column name: ")
    new = input("Enter new column name and its constraint: ")
    obj1.ColumnRename(name4,old,new)

    name5 = input("Enter the table name of which you want to modify column: ")
    col = input("Enter the column name: ")
    con = input("Modify constraint to: ")
    obj1.ModifyColumn(name5,col,con)

    obj2 = DML()

    tname = input("Enter the table name: ")
    id = int(input("Enter your ID: "))
    name = input("Enter the name: ")
    age = int(input("Enter the age: "))
    city = input("Enter the city: ")

    obj2.DataInsert(tname, id, name, age, city)

    tname = input("Enter a table name in which you want to add data: ")
    a=[]
    obj2.DataInsert(tname,a)

    a = []
    obj2.InsertManyCol(a)

    tname = input("Enter a table name: ")
    start = input("Enter the starting charecter: ")
    end = input("Enter the ending charecter: ")
    obj2.Filter(tname,start,end)

    tname = input("Enter a table name: ")
    obj2.deleteByName(tname)

    tname = input("Enter a table name: ")
    obj2.DeleteData(tname)

    tname = input("Enter a table name: ")
    id = int(input("Enter the id: "))
    obj2.Update(tname,id)

    obj3 = DQL()

    obj4 = DCL()

    action = input("Do you want to GRANT or REVOKE permission? (grant/revoke): ").lower()
    username = input("Enter username to modify permissions: ")
    permission = input("Enter permission (e.g., SELECT, INSERT, DELETE): ")
    tname = input("Enter table name to apply permission: ")

    if action == "grant":
        obj4.GrantPrivileges(username, permission, tname)
    elif action == "revoke":
        obj4.RevokePrivileges(username, permission, tname)
    else:
        print("Invalid action for DCL.")


    obj5 = TCL()

    tcl_action = input("Do you want to COMMIT, ROLLBACK, or create a SAVEPOINT? (commit/rollback/savepoint): ").lower()
    if tcl_action == "commit":
        obj5.CommitTransaction()
    elif tcl_action == "rollback":
        obj5.RollbackTransaction()
    elif tcl_action == "savepoint":
        savepoint_name = input("Enter a name for the savepoint: ")
        obj5.SavepointTransaction(savepoint_name)
    else:
        print("Invalid action for TCL.")


if __name__=="__main__":
    main()


















