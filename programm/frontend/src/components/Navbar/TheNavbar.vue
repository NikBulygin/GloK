<template>
<nav ref="navSize" class="nav-wrapper">
  <div class="_container">
    <div class="nav">
      <h3>GloK</h3>
      <div class="_row">
        <NavThemeSwitcher />
      </div>
    </div>
  </div>
</nav>
</template>

<script setup lang="ts">
import NavThemeSwitcher from './NavThemeSwitcher.vue'
</script>

<style scoped lang="scss">
.nav-wrapper {
  position: fixed;
  display: flex;
  align-items: center;
  top: 0;
  width: 100%;
  height: 60px;
  z-index: 8;
  background-color: var(--tp-c);
  backdrop-filter: blur(8px);
}

.nav {
  display: flex;
  width: 100%;
  justify-content: space-between;
  gap: var(--space);
  padding: var(--space);

  h3 {
    text-transform: uppercase;
  }
}
</style>
