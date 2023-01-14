<template>
<div id="menu">
  <div class="menu-icon">
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
    <span class="icon-bar"></span>
  </div>
</div>
</template>

<style scoped lang="scss">
.menu-icon {
  position: relative;
  height: 28px;
  width: 30px;
  display: block;
  z-index: 10;
  transition: transform 0.6s cubic-bezier(0.165, 0.84, 0.44, 1);
  cursor: pointer;
}

.icon-bar {
  position: absolute;
  background-color: var(--txt-c);
  top: 50%;
  right: 6px;
  left: 6px;
  height: 2px;
  width: auto;
  margin-top: -1px;
  transition: 
    transform 0.6s cubic-bezier(0.165, 0.84, 0.44, 1),
    opacity 0.3s cubic-bezier(0.165, 0.84, 0.44, 1);
}

.icon-bar:nth-child(1) {
  -webkit-transform: translateY(-6px);
  transform: translateY(-6px);
}

.icon-bar:nth-child(2) {
  transform-origin: 100% 50%;
  transform: scaleX(.8);
}

.menu-icon:hover .icon-bar:nth-child(2) { transform: scaleX(1); }
.icon-bar:nth-child(2):hover { transform: scaleX(1); }
.icon-bar:nth-child(3) { transform: translateY(6px); }

#menu.active {
  .menu-icon { transform: rotate(-180deg); }
  .icon-bar:nth-child(1) { transform: rotate(45deg); }
  .icon-bar:nth-child(2) { opacity: 0; }
  .icon-bar:nth-child(3) { transform: rotate(-45deg); }
}
</style>
