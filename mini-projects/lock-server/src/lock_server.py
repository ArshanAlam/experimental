# coding: utf8

"""
Written by https://github.com/ArshanAlam
"""

# imports
import uuid

def str_to_uuid(uuid_str):
  return uuid.UUID(str(uuid_str).strip())

class Entity:
  def __init__(self, uuid_str):
    self._uuid = str_to_uuid(uuid_str)

  def get_uuid(self):
    return self._uuid


class Holder(Entity):
  def __init__(self, uuid_str):
    Entity.__init__(self, uuid_str)


class Lock(Entity):
  def __init__(self, uuid_str):
    Entity.__init__(self, uuid_str)
    self._is_locked = False
    self._holder = None


  def is_locked(self):
    return self._is_locked


  def get_holder(self):
    return self._holder


  def lock(self, holder):
    if self.is_locked():
      return False

    self._is_locked = True
    self._holder = holder

    return True


  def unlock(self):
    if not(self.is_locked()):
      return False

    self._holder = None
    self._is_locked = False
    
    return True




# Test
lock = Lock(uuid.uuid4())
holder1 = Holder(uuid.uuid4())
holder2 = Holder(uuid.uuid4())


print("Lock:", lock.get_uuid())
print("Holder 01:", holder1.get_uuid())
print("Holder 02:", holder2.get_uuid())


print()
print("Is Locked:", lock.is_locked())


print()
print("Locking to holder1:", lock.lock(holder1))
print("Is Locked:", lock.is_locked())
print("Lock holder:", lock.get_holder().get_uuid())


print()
print("Locking to holder2:", lock.lock(holder2))
print("Unlock:", lock.unlock())
print("Lock holder:", lock.get_holder())


print()
print("Locking to holder2:", lock.lock(holder2))
print("Is Locked:", lock.is_locked())
print("Lock holder:", lock.get_holder().get_uuid())


print()
print("Locking to holder1:", lock.lock(holder1))
print("Unlock:", lock.unlock())
print("Lock holder:", lock.get_holder())

