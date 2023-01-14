<template>
<TheNavbar />
<AppBackground class="app-background _full-fixed" />
<div class="app-wrapper _full-fixed"></div>
<div class="_container">
  <TheHomeSection />
</div>
</template>

<script setup lang="ts">
import AppBackground from './components/AppBackground.vue'
import TheNavbar from './components/Navbar/TheNavbar.vue'
import TheHomeSection from './components/TheHomeSection.vue'
</script>

<style scoped lang="scss">
.app-wrapper {
  backdrop-filter: blur(40px);
  background-color: var(--tp-c);
  z-index: -1;
}

.app-background { z-index: -2; }
</style>